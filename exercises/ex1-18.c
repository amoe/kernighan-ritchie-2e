#include <stdio.h>

#define MAX_LINE_LENGTH 128

/*
  Exercise 1-18.  Write a program to remove trailing blanks and tabs from each
  line of input, and to delete entirely blank lines.
*/


/* Basic approach: We can't do this on a pure getchar() filtering basis because
   it requires making decisions only after we read a newline.  So we do need
   to read the entire line.

   e.g. hypothetically, if we used getchar(), once we read the trailing blank, we
   would already have emitted it -- as we wouldn't be able to distinguish it from
   a blank that was followed by a non-blank.

   So what we need to do is identify the last non-blank character in each line,
   and emit until that point.

   If we find that the last non-blank character is at position 0, that means
   that the line is blank, and we special case to not emit it at all.
*/

int mygetline(char buffer[], int maxlen) {
    int value;
    int actually_read_length = 0;

    while (1) {
        if (actually_read_length >= (maxlen - 1)) {
            break;
        }

        value = getchar();

        if (value == EOF) {
            break;
        }
        
        buffer[actually_read_length] = value;
        actually_read_length++;
        
        if (value == '\n') {
            break;
        }
    }

    buffer[actually_read_length] = 0;
    return actually_read_length;
}


int main() {
    int i;
    char buffer[MAX_LINE_LENGTH];
    
    while (mygetline(buffer, MAX_LINE_LENGTH)) {
        int len = 0;
        while (buffer[len] != '\n') len++;
        if (len == 0) {
            /* do nothing */
        } else {
            for (i = len - 1; i >= 0; i--) {
                if (buffer[i] == ' ' || buffer[i] == '\t') {
                    /* do nothing */
                } else {
                    break;
                }
            }

            /* add a terminator after the last nonblank */
            buffer[i + 1] = '\0';

            printf("%s\n", buffer);
        }
    }
}
