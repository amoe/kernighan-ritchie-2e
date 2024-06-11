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
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    
    return 0;
}
