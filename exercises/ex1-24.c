#include <stdio.h>


/*
  Exercise 1-24. Write a program to check a C program for rudimentary syntax
  errors like unbalanced parentheses, brackets and braces. Don't forget about
  quotes, both single and double, escape sequences, and comments. (This program
  is hard if you do it in full generality.)
*/

/* This is a mega basic version that only supports parentheses and newlines as
   input. */

int main(void) {
    int c;
    int parenthesis_level = 0;
    int character_count = 0;
    int inside_character_constant = 0;

    while ((c = getchar()) != EOF) {
        character_count++;

        if (c == '\'') {
            /* Flip character constant status on or off */
            inside_character_constant = !inside_character_constant;
        } else if (c == '(') {
            if (inside_character_constant)
                continue;
            parenthesis_level++;
        } else if (c == ')') {
            if (inside_character_constant)
                continue;
            
            if (parenthesis_level == 0) {
                fprintf(
                    stderr,
                    "fatal: found unexpected closing parenthesis at %d\n",
                    character_count
                );
                return 0;
            }
            parenthesis_level--;
        } else if (c == '\n') {
            /* nothing */
        } else {
            fprintf(stderr, "fatal: found character outside of program domain %c\n", c);
            return 1;
        }
    }

    if (parenthesis_level == 0) {
        /*printf("All parentheses in input were balanced.\n");*/
        printf("OK\n");
    } else {
        /*printf("Unbalanced parentheses.  Expected %d closing parentheses.\n", parenthesis_level);*/
        printf("FAIL\n");
    }

    return 0;
}
