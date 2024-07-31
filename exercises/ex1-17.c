#include <stdio.h>

#define MAX_LINE_LENGTH 128

/*
  Exercise 1-17.  Write a program to print all input lines that are longer than
  80 characters.
*/


/* A version of mygetline that will cap out the buffer size at
   maxlen, but will continue counting the length (and consuming
   characters). */
int mygetline_unrestricted(char buffer[], int maxlen) {
    int c;
    int i = 0;

    c = getchar();

    while (c != EOF) {
        /* Note: not < */
        if (i <= maxlen)
            buffer[i] = c;

        i++;
        
        if (c == '\n') break;
        
        c = getchar();
    }

    buffer[i] = '\0';
    
    return i;
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    int length = 0;

    while ((length = mygetline_unrestricted(buffer, MAX_LINE_LENGTH)) != 0) {
        if (length > 80) {
            printf("%s", buffer);
        }
    }
}
