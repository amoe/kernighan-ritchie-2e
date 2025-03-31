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

void print_float(void) {
    /* The maximum exponent is 128 due to the biased representation.
       FIXME: calculate this. */
    int maximum_exponent = 128;

    /* Calculate 2^127 in float */
    int m = 2;
    float result = m;
    int n = maximum_exponent;
    while (--n > 0) {
        result = result * m;
    }

    /* The largest possible value of the mantissa is
       something extremely close to 2.
       How close is defined as (1 + (1 - 2^M)) where M is mantissa size.
    */

    int mantissa_size = 23;

    double blah = negative_expt(2, 23);

    printf("blah is %.\n", blah);
    
    double maximum_mantissa = 1.0 + (1.0 - blah);

    printf("Maximum mantissa = %g\n", maximum_mantissa);
       

    printf("%d^%d = %f\n", m, maximum_exponent, result);

    if (result == FLT_MAX) {
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
