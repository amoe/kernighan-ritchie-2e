#include <stdio.h>

/*
  Exercise 1-21. Write a program 'entab' that replaces strings of blanks by the
  minimum number of tabs and blanks to achieve the same spacing. Use the same
  tab stops as for 'detab'. When either a tab or a single blank would suffice to
  reach a tab stop, which should be given preference?  */

/* Additional stipulations by me (this makes the problem easier):
   Tab characters are not supported in the input.
   The input must end with a newline character.
*/


#define TAB_STOP_SIZE 8

static void emit_spaces(int spaces, int column) {
    int i;
    int tabs;
    int remainder;
    int vspaces = spaces + (column % TAB_STOP_SIZE);

    if (vspaces >= 8) {
        /* Integer division truncates but we know that this will leave us with
           the floor of the value anyway, which is what we want. */
        tabs = vspaces / TAB_STOP_SIZE;
        remainder = vspaces % TAB_STOP_SIZE;
    } else {
        tabs = 0;
        remainder = spaces;
    }
    
    for (i = 0; i < tabs; i++) putchar('\t');
    for (i = 0; i < remainder; i++) putchar(' ');
}

int main() {
    int c;
    int column = 0;
    int inside_space_run = 0;
    int accumulated_spaces = 0;

    while ((c = getchar()) != EOF) {
        /* We only support runs of spaces (not mixed spaces and tabs) */
        if (c == ' ') {
            inside_space_run = 1;
            accumulated_spaces++;
        } else {
            if (inside_space_run) {
                emit_spaces(accumulated_spaces, column);
                column += accumulated_spaces;
            }
            putchar(c);
            inside_space_run = 0;
            accumulated_spaces = 0;

            if (c == '\n') {
                column = 0;
            } else {
                column++;
            }
        }
    }
}
