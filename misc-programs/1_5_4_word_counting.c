#include <stdio.h>

int main() {
    int c;
    int in_word_p = 1;
    
    long lines = 0;
    long words = 0;
    long characters = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++lines;
            in_word_p = 0;
        } else if (c == ' ' || c == '\t') {
            in_word_p = 0;
        } else {
            if (!in_word_p) {
                ++words;
                in_word_p = 1;
            }
        }
            

        ++characters;
    }

    printf("Lines: %ld\n", lines);
    printf("Words: %ld\n", words);
    printf("Characters: %ld\n", characters);
}
