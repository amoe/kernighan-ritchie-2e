#include <stdio.h>

int main(void) {
    printf("Starting.\n");

    /* The bitwise AND operator & is often used to mask off some set of bits;
       for example, set to zero all but the low-order 7 bits of n: */

    /* What does this mean.
       'low-order' probably means the least-significant bits.
       mask off means it would reduce the effective value. */
       
    
    int n = 128;
    n = n & 0177;

    printf("n is %d\n", n);

    printf("End.\n");
    return 0;
}
