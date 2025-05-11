#include <stdio.h>

int myalert() {
    printf("pod bay doors\n");
    return 0;
}

int main(void) {
    /* Arithmetic operators bind more tightly (have higher precedence) than
       relational operators so expressions like this will work ok. */
    /* This proves this, because it would be zero if the other precedence
       applied. */
    int i = 0;
    int lim = 2;
    
    int val1 = i < lim - 1;
    int val2 = i < (lim - 1);

    printf("val1 is %d\n", val1);
    printf("val2 is %d\n", val2);

    /* Logical operators have short circuiting. */

    /* Will print. */
    int val3 = 1 && myalert();

    /* Will not print.   We have strict-order evaluation. */
    int val4 = 0 && myalert();

    /* Will not print as we already know it's true. */
    int val5 = 1 || myalert();

    /* Will print. */
    int val6 = 0 || myalert();
}
