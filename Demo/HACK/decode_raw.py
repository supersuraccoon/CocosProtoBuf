import sys
import subprocess

def decode_raw(data):
    process = subprocess.Popen(
        ['/usr/local/bin/protoc', '--decode_raw'],
        stdin = subprocess.PIPE,
        stdout = subprocess.PIPE,
        stderr = subprocess.PIPE
    )
    output = error = None
    try:
        output, error = process.communicate(data)
    except OSError:
        pass
    finally:
        if process.poll() != 0:
            process.wait()
    return output

f = open(sys.argv[1], "rb")
data = f.read()
print '------ data ------\n'
print data
print '------ ------ ------\n'

print '------ result ------\n'
print decode_raw(data)
print '------ ------ ------\n'
f.close()