#include <stdio.h>

/* 2.5 Write any() function to return the first position found of any letter
   in the given string s2. Clone of strpbrk() function */

int any(char s1[], char s2[]) {
    int i;
    int j;
    int result = -1;

    for (i = 0; s1[i] != '\0' && result == -1; i++) {
        char c = s1[i];

        for (j = 0; s2[j] != '\0'; j++) {
            if (c == s2[j]) {
                result = i;
            }
        }
    }

    return result;
}

int main(void) {
    printf("Starting.\n");

    char input_string[] = "Hello, world!";
    
    int position1 = any(input_string, "e");
    printf("Result is: %d\n", position1);

    int position2 = any(input_string, "le");
    printf("Result is: %d\n", position2);

    int position3 = any(input_string, "a");
    printf("Result is: %d\n", position3);

    /* Expected output: 1, 1, -1 */
    
    
    printf("End.\n");
    return 0;
}
