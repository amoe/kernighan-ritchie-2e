#include <stdio.h>

/* equivalent to wc -c */

int main() {
     /* Must initialize otherwise it will contain undefined value */
    int count = 0;
    int c;   
    
    while ((c = getchar()) != EOF) {
        count = count + 1;    /* we haven't had autoincrement introduced yet */
    }

    printf("%d\n", count);
}
