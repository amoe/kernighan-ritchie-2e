#include <stdio.h>

#define ARRAYLEN 10

/* Void function that modifies its argument to illustrate the point that
   arrays are passed by value in C. */
int modify_array(int the_array[]) {
    int i;
    
    for (i = 0; i < ARRAYLEN; i++) {
        the_array[i] = the_array[i] * 2;
    }

    return 0;   /* just because we haven't been shown void functions yet */
}

int main() {
    int multiples[ARRAYLEN];
    int i;

    for (i = 0; i < ARRAYLEN; i++) {
        multiples[i] = i * 2;
    }

    modify_array(multiples);


    for (i = 0; i < ARRAYLEN; i++) {
        printf("%d\t%d\n", i, multiples[i]);
    }

    return 0;
}
