#include <stdio.h>

int main(void) {
    int foo = 2 + 2;
    int bar = 4 - 2;
    int baz = 2 * 2;

    
    int quux = 10 / 2;

    printf("Whole division result = %d\n", quux);

    /* Integer division truncates the fractional result */
    /* So here, fry = 0 */
    int fry = 1 / 2;
    printf("fry = %d\n", fry);

    /* So here, leela = 2 (truncated from 2.5)*/
    int leela = 5 / 2;
    printf("leela = %d\n", leela);

    /* The truncation direction is machine-dependent for negative
     * operands. So this could be -2 or -3 (in C89) but always -2 (in C99) */
    int negative_trunc = -5 / 2;
    printf("Negative truncation result = %d\n", negative_trunc);

    /* Modulus gives the remainder of dividing two numbers.
       This % operator is not defined on floating-point numbers. */
    int modulus_example = 5 % 2;
    printf("Modulus is %d\n", modulus_example);

}
