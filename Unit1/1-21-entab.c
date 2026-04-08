#include <stdio.h>

int main() {
  // Still assume tab is align to four
  // I think one space is greater than one tab because for tab there's an extra
  // calculation.(Originally I thought like this but no tab is always better because I can process them with one logic)
  // Tab is align not just typing four tabs. it always jump to the 4(or 8) * n
  // location in the line
    int c;
    int counterSpace = 0; // This is a counter for checking how many spaces
    int location = 0;
    while ((c = getchar()) != EOF) {
        location++;
        if (c == ' ') {
            counterSpace++;
            // if at 4*n location and it is a space, i can use a tab to replace it.
            if (location % 4 == 0) {
                putchar('\t');
            }
        } else {
          // Two different branch: 1, not at 4*n, there's already non space
          // character. 2, at 4*n, there is extra spaces.
          // In both cases I need to print out the nonspace character first.
          // Maybe I can merge these two branch into one logic
            while (counterSpace > 0) {
                putchar(' ');
                counterSpace--;
            }
            putchar(c);
        }
    }
    return 0;
}
