#include <stdio.h>

#define MAX_LINE_LENGTH 128


/*
  getline() is a clashing name in OSX, so use mygetline.
  returns 0 if end of file.  Otherwise return line length.  result will include a newline */
int mygetline(char buffer[], int maxlen) {
    int c;
    int i = 0;

    c = getchar();
    
    while (c != EOF) {
        buffer[i++] = c;

        if (c == '\n')
            break;

        if (i > maxlen)
            break;

        c = getchar();
    }

    /* As it stands our buffer won't be null terminated so add a null
       terminator */
    buffer[i] = '\0';

    return i;
}


/* copy from one location to the other.  Prototype implies that they have to
 be null-terminated.*/
void copy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != 0) {
        destination[i] = source[i];
        ++i;
    }
}


int main() {
    char buffer[MAX_LINE_LENGTH];
    char longest[MAX_LINE_LENGTH];
    int length_of_longest = 0;
    int length = 0;
    
    while ((length = mygetline(buffer, MAX_LINE_LENGTH)) != 0) {
        if (length > length_of_longest) {
            copy(buffer, longest);
            length_of_longest = length;
        }
    }

    printf("Longest line: %s\n", longest);
    printf("It had a length of %d characters.\n", length_of_longest);
}
