import subprocess

test_data = [
    (b'foobar\n', b'foobar\n'),
    (b'foo     \n', b'foo\t\n'),
    (b'foobar00foo     \n', b'foobar00foo\t\n'),
    (b'foobar  \n', b'foobar\t\n'),
    (b'foo bar baz quux\n', b'foo bar\tbaz quux\n'),
    (b'foobar0 \n', b'foobar0\t\n'),
    (b'foobar00foobar0 \n', b'foobar00foobar0\t\n'),
    (b'foobar00 oobar0 \n', b'foobar00 oobar0\t\n'),
    (
        b'abcdefghabcd                        efghabcdefgh\n',
        b'abcdefghabcd\t\t\t    efghabcdefgh\n'
    )
]


success = 0

print("Running test suite.")


for test_input, expected in test_data:
    process = subprocess.run(
        './build/ex1-21_tg', check=True, stdout=subprocess.PIPE, input=test_input
    )
    result = process.stdout

    if result != expected:
        raise Exception(f'Test failure:\nActual output {result!r} was not {expected!r}')
    else:
        success += 1
    
#    if result != expected:

print(f"Executed {success} test cases successfully.")
