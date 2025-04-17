#include <stdio.h>

#define MAXLINE 1000

/* Adapted version of strlen from K&R. */
int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int main(void) {
    int some_constant1 = 1234;
    printf("%d\n", some_constant1);
    
    long some_constant2 = 123456789L;
    printf("%ld\n", some_constant2);

    
    float f1 = 123.4;
    printf("%f\n", f1);
    float f2 = 1e-2;
    printf("%f\n", f2);

    /* octal */
    int c1 = 0755;
    printf("%d\n", c1);

    /* hex */
    int c2 = 0x1F;
    printf("%d\n", c2);

    /* character constants */

    /* This will have numeric value 38. */
    int my_char = '0';
    printf("%d\n", my_char);
    
    int newline1 = '\n';
    printf("%d\n", newline1);

    /* Bytes can also be specified with octal, so these are all newlines the same as
     the above. */
    int newline2 = '\012';
    int newline3 = '\x0a';

    printf("%d\n", newline2);
    printf("%d\n", newline3);
    

    /*
      The expression inside the square brackets is evaluated at compile time,
      because all its components are constants.  So this is legal:
    */
    char buffer[MAXLINE + 1];



    /* String pasting across multiple lines happens at compile time. */
    char *constant =
        "hello, "
        "world";
    printf("\"%s\"\n", constant);

    
    /* Basic enum, materializes the symbolic values in the current scope.
       These will have values 0 and 1, and the expression is of type 'int' */
    enum boolean { NO, YES };


    /* The enum type then becomes a type in the current scope as well */
    enum boolean myboolean = NO;
    printf("myboolean = %d\n", myboolean);

    /* However it's not type checked and this won't even generate a warning. */
    enum boolean myboolean2 = 143;
    printf("myboolean2 = %d\n", myboolean2);
}
