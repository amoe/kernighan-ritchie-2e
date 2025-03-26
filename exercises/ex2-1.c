#include <stdio.h>

long get_maximum(unsigned int type_size, int is_signed);
int power(int m, int n);


long get_maximum(unsigned int type_size, int is_signed) {
    if (is_signed) {
        return power(2, (type_size * 8) - 1) - 1;
    } else {
        return power(2, type_size * 8) - 1;
    }
}

int power(int m, int n) {
    int result = m;

    while (--n > 0) {
        result = result * m;
    }

    return result;
}

void print_size(unsigned int type_size, int is_signed) {
    long maximum = get_maximum(type_size, is_signed);

    if (is_signed) {
        printf("Maximum: %ld\n", maximum);
        printf("Minimum: %ld\n", -maximum);
    } else {
        printf("Maximum: %ld\n", maximum);
        printf("Minimum: 0\n");
    }

}

/* Determine the range of various types. */

int main(void) {
    printf("UNSIGNED CHAR:\n");
    print_size(sizeof(signed char), 0);

    printf("SIGNED CHAR:\n");
    print_size(sizeof(signed char), 1);
    
    printf("SIGNED SHORT:\n");
    print_size(sizeof(signed short), 1);
}
