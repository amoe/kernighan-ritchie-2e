#include <stdio.h>

#define MAX_LINE_LENGTH 128

/*
  Exercise 1-16. Revise the main routine of the longest-line program so it will
  correctly print the length of arbitrarily long input lines, and as much as
  possible of the text.

  
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
        printf("Read a line: length = %d\n", length);
        printf("Buffer contents: %s\n", buffer);
    }
}
