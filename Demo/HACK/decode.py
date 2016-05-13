import sys
import subprocess

def decode(message_name, proto_name, bin_name):
    process = subprocess.Popen(
        ['/usr/local/bin/protoc', '--decode', message_name, proto_name],
        stdin = subprocess.PIPE,
        stdout = subprocess.PIPE,
        stderr = subprocess.PIPE
    )

    output = error = None
    try:
        f = open(bin_name, "rb")
        data = f.read()
        f.close()
        output, error = process.communicate(data)
        if error:
            print 'error: ' + error 
    except OSError:
        pass
    finally:
        if process.poll() != 0:
            process.wait()
    return output

print '------ result ------\n'
print 'message_name: ' + sys.argv[1]
print 'proto_name: ' + sys.argv[2]
print 'bin_name: ' + sys.argv[3]
print
print decode(sys.argv[1], sys.argv[2], sys.argv[3])
print '------ ------ ------\n'
