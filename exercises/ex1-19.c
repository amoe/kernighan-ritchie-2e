#include <stdio.h>

#define MAX_LINE_LENGTH 128

int mygetline(char buffer[], int maxlen);

int mygetline(char buffer[], int maxlen) {
    int value;
    int actually_read_length = 0;

    while (1) {
        if (actually_read_length >= maxlen) {
            break;
        }

        value = getchar();

        if (value == EOF) {
            break;
        }
        
        buffer[actually_read_length] = value;
        actually_read_length++;
        
        if (value == '\n' || value == EOF) {
            break;
        }
    }

    buffer[actually_read_length] = 0;
    return actually_read_length;
}


/* so this won't work -- but apparently there is a way to do this -- using
   a temp char */
void reverse(char s[]) {
    int len = 0;
    int i, j;
    
    while (s[len] != 0) len++;    /* calculate length */

    len--;

    for (i = len; i >= 0; i--) {
        j = len - i;
        printf("Moving %d to %d\n", i, j);
        s[j] = s[i];
    }
}


int main() {
    char buffer[MAX_LINE_LENGTH];
    while (mygetline(buffer, MAX_LINE_LENGTH)) {
        reverse(buffer);
        printf("%s", buffer);
    }
}
