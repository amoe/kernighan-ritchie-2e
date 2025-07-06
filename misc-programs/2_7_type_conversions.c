#include <stdio.h>

/* We take an int because this is convention in C, to account for EOF. */
int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        /* Lowercase characters are positioned sequentially after the
           uppercase ones, and are separated by a gap.

           So for instance:

           Uppercase L = decimal 76

           Lowercase 'a' = decimal 97

           Uppercase 'A' = decimal 65

           97 - 65 = 32

           We rely on the alphabet being completely contiguous.
           But there ARE non-alphabetic characters after all of the uppercase
           characters, this doesn't matter though because they get included in
           the gap count.
         */


        char gap_distance = 'a' - 'A';
        return c + gap_distance;
    } else {
        return c;
    }
}


int my_atoi(char s[]);

int my_atoi(char s[]) {
    int i, n;
    n = 0;

    /* The loop will terminate at the first non-digit value. */
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        /* We assume all ASCII digits are contiguously located. */
        char digit_value = s[i] - '0';

        /* Keep multiplying our last value by 10 to increment the position.
           e.g. in the case of 423

           n = 0
           n = 4 (10 * 0 + 4)
           n = 42 (10 * 4 + 2)
           n = 423 (10 * 42 + 3)
           
           */
        
        n = 10 * n + digit_value;
    }

    return n;
}

int main(void) {

    int result = my_atoi("423");

    printf("Value of result is: %d\n", result);

    int foo = lower('L');

    printf("Lowercase L is: '%c'\n", foo);
    
    return 0;
}
