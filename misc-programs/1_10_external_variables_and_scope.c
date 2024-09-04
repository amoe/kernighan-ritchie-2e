#include <stdio.h>

#define MAX_LINE_LENGTH 128

/* These are DEFINITIONS... */
int max;
char longest[MAX_LINE_LENGTH];
char line[MAX_LINE_LENGTH];

int mygetline(void);
void copy(void);


int main() {
    int len;
    /* but these are DECLARATIONS. */
    /* These are technically unnecessary because the definition precedes the
       declaration.  If I redeclared 'max' without 'extern', it would shadow
       the existing 'max' */
    extern int max;
    extern char longest[];

    max = 0;   /* does it need to be init separately?*/

    while ((len = mygetline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    
    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}


int mygetline() {
    int c, i;
    extern char line[];

    /* mega confusing structure here; but just centralizing the read-until-newline
       part into the loop condition.  Note that we also iterate until len-1
       to avoid a buffer overrun when writing the line terminator. */
    for (
        i = 0;
        i < (MAX_LINE_LENGTH - 1) && (c = getchar()) != EOF && c != '\n';
        i++
    ) {
        line[i] = c;
    }

    /* if we terminated on a newline (rather than hitting maxlen), make sure
       we still end up adding the newline to the buffer */
    if (c == '\n') {
        line[i] = c;
        i++;
    }
        
    line[i] = '\0';
    return i;
}

void copy() {
    int i;
    extern char line[], longest[];

    i = 0;

    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
    
}
