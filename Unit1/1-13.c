#include <stdio.h>
#define LONGEST_LENGTH 20
#define IN 0
#define OUT 1
int main(int argc, char *argv[]) {
    int lengthFrequency[LONGEST_LENGTH] = {0};
    int c;
    int state = OUT;
    int lengthCounter = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                if (lengthCounter < LONGEST_LENGTH - 1) {
                    lengthFrequency[lengthCounter]++;

                }
                lengthCounter = 0;
            }
        } else if (state == OUT) {
            state = IN;
            lengthCounter++;
        }else {
            lengthCounter++;
        }
    }

    for (int i = 1; i < LONGEST_LENGTH; i++) {
        printf("%d:%d\t", i, lengthFrequency[i]);
    }

    /*
     * I don't want to output the histogram, however I will
     * explain the logic: for vertical: find largest frequency first,
     * set it as the index, minus by 1 each loop, then create another for loop
     * loop each element in the array, whenever the element's value is
     * <= vertical index, putchar('*'), use \t to separate.
     * after the loop finished, printf to show X axis
     *
     * For horizontal, just double for loop. it's easy
     */
    return 0;

}
