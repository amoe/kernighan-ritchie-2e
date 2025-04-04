#include <stdio.h>
#include <float.h>

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


/* unclear what type to use */
double negative_expt(int m, int n) {
    double result = (double) m;

    while (--n > 0) {
        result = result * ((double) m);
    }

    return 1.0 / result;
}

float binary_power(int n) {
    float result = 2.0;
    float m = 2.0;

    int exponent;
    /* If it's a negative power then we need to make it positive */
    if (n < 0) {
        exponent = -n;
    } else {
        exponent = n;
    }
    

    while (--exponent > 0) {
       result *= m;
    }

    /* If it's a negative power return the reciprocal */
    if (n < 0) {
        return 1 / result;
    } else {
        return result;
    }
}

void print_float(void) {
    /* First calculate 2^127; this is guaranteed to fit in a float.
     The value should be 1.70e38*/

    float maximum_exponent = binary_power(127);
    printf("Result is %g\n", maximum_exponent);

    /* Now calculate 2^-23

       The result should be 1.19e-7
     */
    float epsilon = binary_power(-23);
    
    float max = (2 - epsilon) * maximum_exponent;
    
    if (max == FLT_MAX) {
        printf("This is the largest float.\n");
    } else {
        printf("This is not the largest float.\n");
    }
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

    print_float();


    /* To determine the range of float types.
       You first need to find the size of them,*/
/*
  From p9:
  
  A float number is typically a 32-bit quantity, with at least six significant
  digits and magnitude generally between about 10^-38 and 10^+38.

  What are the ways to calculate this?

  It will depend on the representation.

  So the specs of a float are:
  1 sign bit.
  8 bits for an exponent.
  23 bits for a mantissa.

  1 bit is used for the sign of the overall float.

  8 bits is just a regular exponent and stored as a biased number.  Still the range
  of the exponent runs from -127 to 127.

  23-bit mantissa.  This stores significant digits.

  So the maximum mantissa would be:
  127 exponent.
  All 1 bits of 23 (perhaps) or all 0.
  */
       
}
