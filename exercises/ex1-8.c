#include <stdio.h>

/* 1-8 Write a program to count blanks, tabs, and newlines. */

int main() {
    int c;

    long blanks = 0;
    long tabs = 0;
    long newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        }

        /* We haven't been taught about 'else if' yet, or 'else' for that
           matter, so just use multiple if statements */

        if (c == '\t') {
            ++tabs;
        }

        if (c == '\n') {
            ++newlines;
        }
    }

    printf("%ld\t%ld\t%ld\n", blanks, tabs, newlines);
}
