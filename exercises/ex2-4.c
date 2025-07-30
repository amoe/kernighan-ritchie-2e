#include <stdio.h>
#include <string.h>

/* Write an alternate version of squeeze(s1, s2) that deletes each character in
 * s1 that matches any character in the string s2. */

void squeeze(char s1[], char s2[]) {
    int i, j;
    int should_write;
    int write_position = 0;

    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    

    for (i = 0; i < s1_length; i++) {
        char this_char = s1[i];
        
        should_write = 1;    /* assume we should write it */

        /* This is O(n^2), there's likely a faster method; an obvious one
           would be to create an array with the char value as an index. */
        for (j = 0; j < s2_length; j++) {
            if (this_char == s2[j]) {
                should_write = 0;
            }
        }

        if (should_write) {
            s1[write_position] = this_char;
            write_position++;
        }
    }

    /* The string may now be shorter than it previously was, so terminate
     at the new shorter length.*/
    s1[write_position] = '\0';
}

int main(void) {
    char mystring[] = "The quick brown fox jumped over the lazy dog";
    
    printf("String was: %s\n", mystring);
    squeeze(mystring, "hq");
    printf("String is : %s\n", mystring);
    
    return 0;
}
