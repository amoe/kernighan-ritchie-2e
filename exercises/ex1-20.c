#include <stdio.h>

/* Ex. 1-20: Write a program 'detab' that replaces tabs in the input with the
   proper number of blanks to space to the next tab stop. Assume a fixed set of
   tab stops, say every n columns. Should n be a variable or a symbolic
   parameter? */

#define TAB_STOP_SIZE 8

void emit_soft_tab() {
    int i;
    char tab[TAB_STOP_SIZE + 1];
    
    for (i = 0; i < TAB_STOP_SIZE; i++) {
        tab[i] = ' ';
    }

    tab[i] = '\0';

    printf("%s", tab);
}

int main() {
    int c = 0;
    
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            emit_soft_tab();
        } else {
            putchar(c);
        }
    }
}
