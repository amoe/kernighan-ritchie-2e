#include <stdio.h>

/*
  Exercise 1-22: Write a program to "fold" long input lines into two or more
  shorter lines after the last non-blank character that occurs before the Nth
  column of input.  Make sure your program does something intelligent with very
  long lines, and if there are no blanks or tabs before the specified column.
*/

#define COLUMN_WIDTH 8
#define LINE_BUFFER_SIZE 128

void spit_line(char buffer[], int column) {
    fprintf(stderr, "spitting line of width %d", column);
    
    int virtual_length;
    int i = column;

    /* Count backwards to the last space */
    while (i >= 0 && buffer[i] != ' ') i--;

    virtual_length = i;

    /* spit the line */
    for (i = 0; i < virtual_length; i++) putchar(buffer[i]);

    putchar('\n');

    /* now we still have a remnant of a line which we just output straight away */
    for (i = virtual_length; i < column; i++) putchar(buffer[i]);
}

int main(void) {
    int c;
    int column = 0;
    char line[LINE_BUFFER_SIZE];

    while ((c = getchar()) != EOF) {
        if (column > (LINE_BUFFER_SIZE - 1)) {
            /* We would overflow the buffer if we attempted to store the
               character. So just spit out the line.*/
            /*spit_line(line, column);*/
            /* not sensible, just noisily break */
            return 0;
        } else if (column > COLUMN_WIDTH) {
            spit_line(line, column);
        }
        
        /* Line array is zero based */
        line[column] = c;

        /* After this, column is 1-based: on the first character, column will be
           1 */
        column++;

        if (c == '\n') {
            spit_line(line, column);
            column = 0;
        }
    }

    if (column > 0) {
        spit_line(line, column);
    }
}
