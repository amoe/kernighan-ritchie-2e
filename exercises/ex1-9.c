#include <stdio.h>

/*
  1-9 Write a program to copy its input to its output, replacing each string of
  one or more blanks by a single blank.
*/


int main() {
    int c;
    int inside_blank_run = 0;   /* boolean value */

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!inside_blank_run) {
                putchar(' ');
            }
            inside_blank_run = 1;
        } else {
            inside_blank_run = 0;

            putchar(c);
        }
    }
}
