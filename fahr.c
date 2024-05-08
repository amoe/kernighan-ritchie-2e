#include <stdio.h>

/* Print integer-valued temperature tables for Fahrenheit and Celcsius */

main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper) {
        /* If we used 5/9, the result would be an int but it would be
           truncated, meaning that all celsius results would be zero. */
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
