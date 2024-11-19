#include <stdio.h>

/* Ex. 1-20: Write a program 'detab' that replaces tabs in the input with the
   proper number of blanks to space to the next tab stop. Assume a fixed set of
   tab stops, say every n columns. Should n be a variable or a symbolic
   parameter? */

#define TAB_STOP_SIZE 8

static void emit_soft_tab(int n_spaces) {
    int i;
    char tab[TAB_STOP_SIZE + 1];
    
    for (i = 0; i < n_spaces; i++) {
        tab[i] = ' ';
    }

    tab[i] = '\0';

    printf("%s", tab);
}

int main() {
    int c = 0;
    int chars_of_line_output = 0;
    int remaining_spaces;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            /* Calculate the remaining spaces to reach the next tab stop.  Using
             * the modulus means that we break the line into equal sized pieces
             * of TAB_STOP_SIZE.  The difference between the tab stop size and
             * the amount of characters already seen in this 'piece' is the
             * amount of spaces we should emit. */
            remaining_spaces = TAB_STOP_SIZE - (chars_of_line_output % TAB_STOP_SIZE);
            emit_soft_tab(remaining_spaces);
            chars_of_line_output += remaining_spaces;
        } else if (c == '\n') {
            putchar(c);
            chars_of_line_output = 0;
        } else {
            putchar(c);
            chars_of_line_output++;
        }
    }
}
