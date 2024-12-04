#include <stdio.h>

/* Exercise 1-23. Write a program to remove all comments from a C program.
   Don't forget to handle quoted strings and character constants properly. C
   comments do not nest. */

/* This program is basically a state machine with a fair few states.  It would
   probably be better modelled more formally.  This version doesn't support
   quoted strings. */

int main(void) {
    int c;
    int seen_forward_slash = 0;
    int seen_asterisk = 0;
    int inside_comment = 0;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if (inside_comment) {
                if (seen_asterisk) {
                    inside_comment = 0;
                }
            } else {
                /* possible start of a comment, don't emit */
                seen_forward_slash = 1;
            }                
        } else if (c == '*') {
            if (inside_comment) {
                /* possible end of a comment, don't emit */
                seen_asterisk = 1;
            } else {
                /* possible start of a comment */
                if (seen_forward_slash) {
                    inside_comment = 1;
                    seen_forward_slash = 0;
                } else {
                    putchar('*');
                }
            }
        } else {
            if (inside_comment) {
                /* do not emit */
            } else {
                if (seen_forward_slash) {
                    /* false alarm */
                    putchar('/');
                    seen_forward_slash = 0;
                }
                putchar(c);
            }
        }
    }
}
