#include <stdio.h>

/* 1.5.3 -- count lines of input (wc -l) */

int main() {
    int c;
    long count = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++count;
        }
    }

    printf("%ld\n", count);
}
