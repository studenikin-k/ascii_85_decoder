import subprocess
import random
import string

ASCII85_BINARY = "./build/ascii85"


def run_ascii85(args, input_bytes):
    proc = subprocess.Popen(
        [ASCII85_BINARY] + args,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        )
    out, err = proc.communicate(input=input_bytes)
    return proc.returncode, out, err


def test_encode_decode():
    text = b"Hello World"
    ret, encoded, _ = run_ascii85(["-e"], text)
    assert ret == 0

    ret, decoded, _ = run_ascii85(["-d"], encoded)
    assert ret == 0
    assert decoded.rstrip(b"\n") == text


def test_decode_invalid_input():
    bad_input = b"@@@@@"  # вне диапазона ASCII85 символов
    ret, _, _ = run_ascii85(["-d"], bad_input)
    assert ret != 0


def test_random():
    for _ in range(2):
        s = b'dsfsdfdsfdsfsdfdsfdfas2342342342'
        ret, encoded, _ = run_ascii85(["-e"], s)
        assert ret == 0

        ret, decoded, _ = run_ascii85(["-d"], encoded)
        assert ret == 0
        assert decoded.rstrip(b"\n") == s


def test_random_binary_data():
    for _ in range(2):
        data = bytes(random.getrandbits(8) for _ in range(15))
        ret, encoded, _ = run_ascii85(["-e"], data)
        assert ret == 0

        ret, decoded, _ = run_ascii85(["-d"], encoded)
        assert ret == 0
        assert decoded.rstrip(b"\n") == data
