#include <stdio.h>

/* Ex2-2.  Write a loop equivalent to [given loop] without using && or ||. */

#define BUFFER_LENGTH 1024

void mygetline(char s[]);

void mygetline(char s[]) {
    int i;
    int lim = BUFFER_LENGTH;
    char c;
    int should_continue = 1;
    
    i = 0;
    while (should_continue) {
        c = getchar();

        should_continue = i < lim - 1;
        
        if (c == '\n') {
            should_continue = 0;
        }

        if (c == EOF) {
            should_continue = 0;
        }

        if (should_continue) {
            s[i] = c;
        }
        ++i;
    }
        
}

int main(void) {
    char buffer[BUFFER_LENGTH];

    mygetline(buffer);

    printf("Read value was: \"%s\"\n", buffer);
}
