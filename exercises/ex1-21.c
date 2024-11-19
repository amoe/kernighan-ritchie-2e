#include <stdio.h>

/*
  Exercise 1-21. Write a program 'entab' that replaces strings of blanks by the
  minimum number of tabs and blanks to achieve the same spacing. Use the same
  tab stops as for 'detab'. When either a tab or a single blank would suffice to
  reach a tab stop, which should be given preference?  */

#define TAB_STOP_SIZE 8

void spit_optimized_spaces(int n_spaces) {
    int number_of_tabs = n_spaces / TAB_STOP_SIZE;
    int remainder = n_spaces % TAB_STOP_SIZE;
    int i;

    /*
    printf("Spaces counted: %d\n", n_spaces);
    printf("Number of tabs: %d\n", number_of_tabs);
    printf("Remainder: %d\n", remainder);
    */

    for (i = 0; i < number_of_tabs; i++) {
        putchar('\t');
    }

    for (i = 0; i < remainder; i++) {
        putchar(' ');
    }
}


int main() {
    int c;

    int is_inside_space_run;
    int spaces_accumulated = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces_accumulated++;
            is_inside_space_run = 1;
        } else {
            /* End of run of spaces */
            if (is_inside_space_run) {
                spit_optimized_spaces(spaces_accumulated);
            }

            /* Reset everything */
            is_inside_space_run = 0;
            spaces_accumulated = 0;
            putchar(c);
        }        
    }
}
