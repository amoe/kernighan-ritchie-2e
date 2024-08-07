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

int mygetchar(int *result) {
    int value = getchar();
    *result = value;
    return value != EOF && value != '\n';
}

int mygetline(char buffer[], int maxlen) {
    int value;
    
    while (mygetchar(&value)) {
        putchar(value);
    }
}

int main() {
    mygetline(NULL, NULL);
}
