#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

#define MAXIMUM_WORD_LENGTH 256

int main() {
    int state = OUTSIDE_WORD;
    int current_word_length = 0;
    int c, i;

    int word_length[MAXIMUM_WORD_LENGTH];
    for (i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
        word_length[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t'  || c == '\n') {
            if (state == INSIDE_WORD) {
                if (current_word_length > MAXIMUM_WORD_LENGTH) {
                    printf("Word too long!");
                    return 1;
                }

                word_length[current_word_length]++;
                state = OUTSIDE_WORD;
                current_word_length = 1;
            }
        } else {
            state = INSIDE_WORD;
            ++current_word_length;
        }
    }

    for (i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
        if (word_length[i] > 0) {
            printf("%d\t%d\n", i, word_length[i]);
        }
    }
    
}
