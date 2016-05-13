#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Erik Weathers : https://github.com/erikdw
#
# Wrapper around protoc's --decode or --decode_raw options, providing support
# for length-prefixed messages (which are not directly supported by `protoc`).
#
# Our definition of 'length-prefixed protobuf messages':
#
#   Length-prefix headers are used to frame protobuf messages when writing
#   to files or TCP streams.  A length-prefix is a header before each message
#   in the data stream which contains the length in bytes of the subsequent
#   message.
#
#   See:
#     https://developers.google.com/protocol-buffers/docs/techniques?csw=1#streaming
#     http://eli.thegreenplace.net/2011/08/02/length-prefix-framing-for-protocol-buffers
#
# Not only can a single length-prefixed message be decoded, but an input
# stream containing a sequence of such messages is supported.
#
# Just like protoc, this allows the user to specify:
#   * the proto source files (bare arguments after the options, just like protoc)
#   * the proto import paths (-I/--proto_path, just like protoc)
#   * the MESSAGE_TYPE to use for decoding (--decode, just like protoc)
#
# Extra options:
#   * -H/--header_size : number of bytes the length-prefix header occupies
#                        (4 bytes by default)
#   * -n/--ntohl : whether the length-prefix header needs to be converted from
#                  big-endian/network byte order to this machine's byte order.
#                  (false by default)
#
# Example usage for decoding a Mesos task.updates file:
#
#   protoc-decode-lenprefix --decode mesos.internal.StatusUpdateRecord \
#                           -I MESOS_CODE/src -I MESOS_CODE/include \
#                           MESOS_CODE/src/messages/messages.proto \
#                           < task.updates
#
#   protoc-decode-lenprefix --decode_raw < task.updates
#
# Notably with a single message in your input file, the --decode_raw invocation
# is equivalent to using `protoc --decode_raw` directly, if you use `dd` to strip
# off the 1st 4 bytes of the input message:
#
#   dd bs=1 skip=4 if=task.info 2>/dev/null | protoc --decode_raw
#

from __future__ import print_function
from subprocess import Popen, PIPE, STDOUT
import argparse
import socket
import struct
import sys
import os

# TODO: Support config file for specifying CLI arguments (to make repeated usage terser).
#  Use ConfigParser for this:
#       http://stackoverflow.com/a/5826167/318428

PROTOC_COMMAND='protoc'

def error(*objs):
    print("ERROR:", *objs, file=sys.stderr)

def ensure_protoc_available():
    for path in os.environ["PATH"].split(os.pathsep):
        exe = os.path.join(path, PROTOC_COMMAND)
        if os.path.isfile(exe) and os.access(exe, os.X_OK):
            return
    error('%s command not found, please install the protobuf package' %
        PROTOC_COMMAND)
    sys.exit(1)

def print_message(args, message_num, message_bytes):
    cmd = [PROTOC_COMMAND]
    if args.decode:
        for proto_path in args.proto_path:
            cmd.append('-I' + proto_path)
        cmd.append('--decode=' + args.decode)
        for proto_file in args.PROTO_FILE:
            cmd.append(proto_file)
    else:
        cmd.append('--decode_raw')
    try:
        p = Popen(cmd, stdout=PIPE, stdin=PIPE, stderr=PIPE)
        comm_data = p.communicate(input=message_bytes)
        stdout_data = comm_data[0]
        stderr_data = comm_data[1]
    except Exception as e:
        error('Exception `%s` when executing `%s`' % (e, ' '.join(cmd)))
        sys.exit(1)
    if stdout_data:
        print("---- message #%d ----\n%s" % (message_num, stdout_data))
    if stderr_data:
        print("---- message #%d ==> ERROR: %s returned error output ----\n%s" %
            (message_num, PROTOC_COMMAND, stderr_data))

def main(args):
    ensure_protoc_available()
    try:
        message_len_header = sys.stdin.read(args.header_size)
        message_num = 0
        while message_len_header != "":
            message_len = struct.unpack('i', message_len_header)[0]
            if (args.ntohl):
                message_len = socket.ntohl(message_len)
            message_bytes = sys.stdin.read(message_len)
            message_num += 1
            print_message(args, message_num, message_bytes)
            message_len_header = sys.stdin.read(args.header_size)
    except Exception as e:
        error('Exception `%s` when parsing standard input' % (e))
        sys.exit(1)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
                description='Decodes length-prefixed protobuf messages passed via stdin.')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument(
        '--decode',
        metavar='MESSAGE_TYPE',
        help='Read a binary message of the given type from standard input and ' \
             'write it in text format to standard output.  The message type ' \
             'must be defined in PROTO_FILES or their imports.')
    group.add_argument(
        '--decode_raw',
        action='store_true',
        help='Read a binary message of the given type from standard input and ' \
             'write it in text format to standard output.  The message type ' \
             'must be defined in PROTO_FILES or their imports.')
    parser.add_argument(
        'PROTO_FILE',
        nargs='*',
        help='Protobuf definition files, typically suffixed with ".proto". ' \
             'Pass a list of such files by separating them with spaces.')
    parser.add_argument(
        '-I', '--proto_path',
        metavar='PATH',
        action='append',
        help='Specify the directory in which to search for imports.  May be ' \
             'specified multiple times; directories will be searched in order. ' \
             'If not given, the current working directory is used.')
    parser.add_argument(
        '-n', '--ntohl',
        action='store_true',
        default=False,
        help="Whether to use the `ntohl` function to convert the prefix-length " \
             "headers from big-endian/network byte order to this machine's byte order. " \
             "Disabled by default.")
    parser.add_argument(
        '-H', '--header_size',
        type=int,
        default=4,
        help="Size in bytes of the length-prefix header for each message.")
    args = parser.parse_args()

    if (args.decode and len(args.PROTO_FILE) == 0):
        error("Missing input file.")
        sys.exit(1)
    if (args.decode_raw and args.PROTO_FILE):
        error("When using --decode_raw, no input files should be given.")
        sys.exit(1)

    main(args)