#include <stdio.h>
#include <float.h>

long get_maximum(unsigned int type_size, int is_signed);
int power(int m, int n);
int get_max_exponent(int bits);


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

/* Another version of the binary power function that results in a double */
double bpowerd(int n) {
    double result = 2.0;
    double m = 2.0;

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

    float maximum_exponent = binary_power(get_max_exponent(8));
    printf("Result is %g\n", maximum_exponent);

    /* Now calculate 2^-23

       The result should be 1.19e-7
     */
    float epsilon = binary_power(-23);
    
    float max = (2 - epsilon) * maximum_exponent;
    printf("float: Max = %g\n", max);
    
    if (max == FLT_MAX) {
        printf("This is the largest float.\n");
    } else {
        printf("This is not the largest float.\n");
    }

    float min = binary_power(-126);
    printf("float: Min = %g\n", min);
    

    if (min == FLT_MIN) {
        printf("This is the smallest float.\n");
    } else {
        printf("This is not the smallest float.\n");
    }
}

int get_max_exponent(int bits) {
    /* The bias is always (2^n-1)-1.
       E.g. for 8 bits this will be 127.
     */
    int bias = power(2, bits - 1) - 1;

    /* The top of the range of a 'normal' unsigned number is given by
       (2^n)-1, e.g. for 8 bits this will be 255. */
    int max_representable = power(2, bits) - 1;

    /* To get the actual max we subtract one (to account for the reserved
     value representing infinity) and then subtract the bias. */
    return max_representable - 1 - bias;
}

void print_double(void) {
    /* The size of a double is:
       11 bit exponent
       52 bit mantissa
       */
    
    double maximum_exponent = bpowerd(get_max_exponent(11));
    printf("double: maximum exponent is %g\n", maximum_exponent);

    /* Now calculate 2^-23

       The result should be 1.19e-7
     */
    double epsilon = bpowerd(-52);
    
    double max = (2 - epsilon) * maximum_exponent;
    printf("Maximum: %g\n", max);
    
    if (max == DBL_MAX) {
        printf("This is the largest double.\n");
    } else {
        printf("This is not the largest double.\n");
    }

    double min = bpowerd(-(get_max_exponent(11) - 1));

    printf("double: Min = %g\n", min);
    if (min == DBL_MIN) {
        printf("This is the smallest double.\n");
    } else {
        printf("This is not the smallest double.\n");
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
    print_double();
}
