#include <stdio.h>

/*
  Exercise 1-22: Write a program to "fold" long input lines into two or more
  shorter lines after the last non-blank character that occurs before the Nth
  column of input.  Make sure your program does something intelligent with very
  long lines, and if there are no blanks or tabs before the specified column.
*/

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
