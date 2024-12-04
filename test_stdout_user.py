import subprocess
import test_data

programs = [
    ('build/ex1-21', test_data.ex_1_21),
#    ('build/ex1-22', test_data.ex_1_22),
    ('build/ex1-24', test_data.ex_1_24),
]
    

print("Running test suite.")


for program, test_suite in programs:
    success = 0
    print("Test program:", program)
    for test_input, expected in test_suite():
        process = subprocess.run(
            program, check=True, stdout=subprocess.PIPE, input=test_input
        )
        result = process.stdout

        if result != expected:
            raise Exception(f'Test failure:\nActual output {result!r} was not {expected!r}')
        else:
            success += 1
    print(f"Executed {success} test cases successfully.")
