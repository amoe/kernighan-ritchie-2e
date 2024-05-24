#include <stdio.h>

int main() {
    int c;
    int i;
    
    int whitespace_count = 0;
    int other_count = 0;
    int digit_count[10];

    /* Initialize the digit count array. */
    for (i = 0; i < 10; i++)
        digit_count[i] = 0;
    

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            int digit_index = c - '0';
            ++digit_count[digit_index];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++whitespace_count;
        } else {
            ++other_count;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; i++) {
        printf(" %d", digit_count[i]);
    }
    printf(", white space = %d, other = %d\n", whitespace_count, other_count);
}
