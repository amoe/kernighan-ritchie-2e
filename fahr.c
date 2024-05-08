#include <stdio.h>

/* Print integer-valued temperature tables for Fahrenheit and Celcsius */

main() {
    int fahr;
    float celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper) {
        /* Now we are using floats.  We must divide by 9.0 rather than 9 here,
           otherwise the sub-integral precision is still lost. */
           
        celsius = 5 * (fahr - 32) / 9.0;
        printf("%3d\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
