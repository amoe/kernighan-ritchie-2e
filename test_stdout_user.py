import subprocess

test_data = [
    (b'foobar\n', b'foobar\n')
]


success = 0

print("Running test suite.")

for test_input, expected in test_data:
    process = subprocess.run(
        './build/ex1-21', check=True, stdout=subprocess.PIPE, input=test_input
    )
    result = process.stdout

    if result != expected:
        raise Exception(f'Failure: {result!r} was not {expected!r}')
    else:
        success += 1
    
#    if result != expected:

print(f"Executed {success} test cases successfully.")
