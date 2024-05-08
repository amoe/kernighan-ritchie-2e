#include <stdio.h>

/* Print integer-valued temperature tables for Fahrenheit and Celcsius */

main() {
    int celsius;
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    while (celsius <= upper) {
        fahr = ((9.0 / 5.0) * celsius) + 32;
        printf("%3d\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
