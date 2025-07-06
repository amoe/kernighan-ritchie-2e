#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned char integer_from_hex(char input);


/* xxx: we do these checks twice, so this is arguably a bit slow */
int is_hex_digit(char input) {
    int is_zero_to_nine = input >= '0' && input <= '9';
    int is_a_to_f_lowercase = input >= 'a' && input <= 'f';
    int is_a_to_f_uppercase = input >= 'A' && input <= 'F';

    return is_zero_to_nine || is_a_to_f_lowercase || is_a_to_f_uppercase;
}


unsigned int htoi(char input[]) {
    /* If input is e.g. ff, value should be 255
       How do we get this?  The number system is 16-base.
       So, f = 15 * 16 + 15
       We can reuse the atoi algorithm.
     */

    int i = 0;
    int n = 0;

    /* skip over optional prefix */
    if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        i = 2;
    }
    
    while (is_hex_digit(input[i])) {
        n = 16 * n + integer_from_hex(input[i]);
        i++;
    }

    return n;

}

unsigned char integer_from_hex(char input) {
    /* If the input is f, then

       a = 10
       b = 11
       c = 12
       d = 13
       e = 14
       f = 15
       */

    if (input >= '0' && input <= '9') {
        /* The value is the offset from the position of '0' */
        return input - '0';
    } else if (input >= 'a' && input <= 'f') {
        /* A hexadecimal digit */
        return 10 + (input - 'a');
    } else if (input >= 'A' && input <= 'F') {
        return 10 + (input - 'A');
    } else {
        abort();
    }
}

int main(void) {
    /* printf("Decimal value of '9' is: %d\n", integer_from_hex('9')); */
    /* printf("Decimal value of 'f' is: %d\n", integer_from_hex('f')); */

    /* printf("htoi value of \"f\" is: %d\n", htoi("f")); */
    printf("htoi value of \"ff\" is: %d\n", htoi("ff"));
    printf("htoi value of \"deadbeef\": %u\n", htoi("deadbeef"));
    printf("htoi value of \"0xDEADBEEF\": %u\n", htoi("0xDEADBEEF"));
}
