#include <stdio.h>

/*
  Ex 1-13: Write a program to print a histogram of the lengths of words in its
  input. It is easy to draw the histogram with the bars horizontal; a vertical
  orientation is more challenging.
*/

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

#define MAXIMUM_WORD_LENGTH 256

int main() {
    int max_value = 0;
    int state = OUTSIDE_WORD;
    int current_word_length = 0;
    int c, i;

    /* These are used later */
    int row;
    int value;

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

    /*
      At this stage, we have an array of up-to-256 values.   Most of them will
      be zero.  The array should be considered sparse.

      To draw vertically orientated lines, we need to treat each column as
      representing a separate array index.

      We also need to know the highest value ahead of time.

    */

    /* After this loop, the max value is stored in max_value -- this gives us
       the number of rows we will draw. */
    for (i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
        if (word_length[i] > 0) {
            if (word_length[i] > max_value)
                max_value = word_length[i];
        }
    }


    /*
      The loop will count down, and skip the final value.  There are no zero-length words.
      We have to pad the length of everything to three digits to avoid
      misaligning the columns when you get longer values.
     */
    for (row = max_value; row > 0; row--) {
        for (i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
            value = word_length[i];
            if (value > 0) {
                if (value >= row) {
                    printf("%3c ", '#');
                } else {
                    printf("%3c ", ' ');
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < MAXIMUM_WORD_LENGTH; i++) {
        value = word_length[i];
        if (value > 0) {
            printf("%3d ", i);
        }
    }

    printf("\n");
}
