#include <stdio.h>

#define TABINC 8

int main(void) {
    int c, nb, nt, pos;

    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar()) != EOF; pos++) {
        if (c == ' ') {
            if ((pos % TABINC) != 0) {
                /* we are not at a tab stop boundary yet so add one space */
                nb++;    
            } else {
                /* we hit the boundary, consume all blanks with a single tab */
                nb = 0;
                ++nt;
            }
        } else {
            /* spit all the tabs */
            for (; nt > 0; --nt)
                putchar('\t');

            /* spit all the spaces */
            for (; nb > 0; --nb)
                putchar(' ');

            /* spit the actual character */
            putchar(c);

            /* reset at end of line */
            if (c == '\n') {
                pos = 0;
            }
        }
    }
}
