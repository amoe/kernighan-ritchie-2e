#include <stdio.h>

#define MAX_LINE_LENGTH 128

int main() {
    char current_line[MAX_LINE_LENGTH];
    char longest_line[MAX_LINE_LENGTH];
    int length_of_accumulated_line = 0;
    int length_of_longest = 0;
    int i;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            /* line is finished */
            if (length_of_accumulated_line > length_of_longest) {
                length_of_longest = length_of_accumulated_line;

                /* need to copy the current buffered line into a more permanent
                   location */
                for (i = 0; i < MAX_LINE_LENGTH; i++) {
                    longest_line[i] = current_line[i];
                }
            }

            length_of_accumulated_line = 0;
        } else {
            current_line[length_of_accumulated_line++] = c;
        }
    }

    /* now longest_line contains the line */

    printf("Longest line: %s\n", longest_line);
    printf("It had a length of %d characters.\n", length_of_longest);
}
