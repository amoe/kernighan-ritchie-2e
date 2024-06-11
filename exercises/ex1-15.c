#include <stdio.h>

/* Rewrite the temperature conversion program of section 1.2 to use a function
 * for conversion. */

float celsius(int fahr) {
    return 5 * (fahr - 32) / 9.0;
}

int main() {
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("  F      C\n");

    while (fahr <= upper) {
        printf("%3d\t%6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}
