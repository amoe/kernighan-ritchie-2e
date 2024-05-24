#include <stdio.h>

int main() {
    int c;
    int i;
    
    /*int whitespace_count;
    int other_count;*/
    int digit_count[10];

    /* Initialize the digit count array. */
    for (i = 0; i < 10; i++)
        digit_count[i] = 0;
    

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            int digit_index = c - '0';
            ++digit_count[digit_index];
        }
    }

    printf("digits =");
    for (i = 0; i < 10; i++) {
        printf(" %d", digit_count[i]);
    }
    putchar('\n');
}
