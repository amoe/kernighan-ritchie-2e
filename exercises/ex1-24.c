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

    while ((c = getchar()) != EOF) {
        character_count++;
        
        if (c == '(') {
            parenthesis_level++;
        } else if (c == ')') {
            if (parenthesis_level == 0) {
                printf(
                    "fatal: found unexpected closing parenthesis at %d\n",
                    character_count
                );
                return 0;
            }
            parenthesis_level--;
        } else if (c == '\n') {
            /* nothing */
        } else {
            fprintf(stderr, "Only parentheses are supported as input.\n");
            return 1;
        }
    }

    if (parenthesis_level == 0) {
        printf("All parentheses in input were balanced.\n");
    } else {
        printf("Unbalanced parentheses.  Expected %d closing parentheses.\n", parenthesis_level);
    }

    return 0;
}
