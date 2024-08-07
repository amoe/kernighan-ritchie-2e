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


void reverse(char s[]) {
    int len = 0;
    char temp;
    int i, j;

    while (s[len] != 0 && s[len] != '\n') len++;    /* calculate length */

    /* Each step of the loop processes both sides of the string at once, so we
       only need to iterate to the middle.
       
       In the case of e.g. the string "gleand", the len will be 6.   len-1/2 will be 5/2 = 2.5 = 2.
       
       So the final value will be i = 3, j = 2 which is correct; it swaps 'a' with 'e'.
       If we went on to handle i = 2, j = 3, we would swap 'e' with 'a', undoing
       the previous swap, which would be wrong.
    */
       
    for (i = len - 1; i > (len - 1) / 2; i--) {
        j = len - i - 1;
        
        /* Repeatedly swap values using a temp value. */
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}


int main() {
    char buffer[MAX_LINE_LENGTH];
    while (mygetline(buffer, MAX_LINE_LENGTH)) {
        reverse(buffer);
        printf("%s", buffer);
    }
}
