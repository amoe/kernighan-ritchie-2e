#include <stdio.h>

int main(void) {
    printf("Size of int: %ld bit\n", sizeof(int) * 8);
    printf("Size of char: %ld bit\n", sizeof(char) * 8);
    printf("Size of float: %ld bit\n", sizeof(float) * 8);    
    printf("Size of double: %ld bit\n", sizeof(double) * 8);    
    printf("Size of long double: %ld bit\n", sizeof(long double) * 8);    
}
