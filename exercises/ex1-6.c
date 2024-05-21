#include <stdio.h>

/* Ex 1.6: Verify that the expression `getchar() != EOF` is 0 or 1. */

int main() {
    int c;

    /* Extra parentheses are needed here to silence a compiler warning. */
    while (1) {
        c = (getchar() != EOF);
        printf("Value of c is: %d\n", c);

        if (!c) {
            break;
        }
    }
}
