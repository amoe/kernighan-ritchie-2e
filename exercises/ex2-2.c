#include <stdio.h>

#define BUFFER_LENGTH 1024

void mygetline(char s[]);

void mygetline(char s[]) {
    int i;
    int lim = BUFFER_LENGTH;
    char c;
    
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;

}

int main(void) {
    char buffer[BUFFER_LENGTH];

    mygetline(buffer);

    printf("Read value was: \"%s\"\n", buffer);
}
