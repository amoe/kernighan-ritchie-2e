#include <stdio.h>

/* We don't handle the case of raising to zero or raising to a negative power */
int power(int m, int n) {
    int result = m;
    
    while (--n > 0) {
        result = result * m;
    }

    return result;
}

int main() {
    int result = power(2, 8);

    printf("2^8 = %d\n", result);
    printf("2^1 = %d\n", power(2, 1));
    printf("2^0 = %d\n", power(2, 0));
}
