#include <stdio.h>


/*
  Delete all of the character 'c' from the string 's'.
  Walk along the string and maintain two indices.

  The first index is the 'source' index and maxes out at the length
  of the string.

  The second index is how far we've copied.  As long as 'c' doesn't appear,
  then i == j.  But if c is skipped, then j < i.  For instance,

  c = 'z'
  s = "xyzzy"

  At the first z, i = 2 and j = 2
  We skip the if block, and in the next iteration, i = 3 and j = 2
  We skip the if block, and in the next iteration, i = 4 and j = 2
  The character 'y' gets written at position 2, and the result is "xyy".
*/
void squeeze(char s[], int c) {
    int i;
    int j;

    for (
        i = j = 0;
        s[i] != '\0';
        i++
    ) {
        if (s[i] != c) {
            /* Using postincrement here is important because otherwise
               we would be writing one position ahead. */
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}


int main(void) {
    printf("Starting.\n");

    char buffer[] = "xyzzy";

    squeeze(buffer, 'z');

    printf("Value in buffer is: %s\n", buffer);

    printf("End.\n");
    return 0;
}
