#include <stdio.h>

#define MAXIMUM_CHAR_VALUE 127

int main() {
    /* We basically assume that a char has a sizeof */

    int histogram[MAXIMUM_CHAR_VALUE];
    int c, i;

    /* Initialize all values to zero */

    for (i = 0; i < MAXIMUM_CHAR_VALUE; i++)
        histogram[i] = 0;
    
    while ((c = getchar()) != EOF) {
        ++histogram[c];
    }

    for (i = 0; i < MAXIMUM_CHAR_VALUE; i++) {
        if (histogram[i] > 0) {
            printf("%3d\t%c\t%d\n", i, i, histogram[i]);
        }
    }
       
}
