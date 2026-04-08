#include <stdio.h>

int main(int argc, char *argv[]) {
    // Assume tab is always allign to 4
    int c;
    int counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int numRepeat = 4 - counter%4;
            while (numRepeat > 0) {
                putchar(' ');
                counter++;
                numRepeat--;
            }
        } else if (c == '\n') {
            putchar(c);
            counter = 0;
            continue;
        } else {
            putchar(c);
        }
        counter++;
    }

    return 0;
}
