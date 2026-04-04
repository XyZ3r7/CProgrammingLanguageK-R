#include <stdio.h>

// Read Input
// Check consecutive spaces,
// Output
int main() {
    int c;
    int prevc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (c != prevc) {
                putchar(c);
            }
        } else {
            putchar(c);
        }
        prevc = c;
    }

    return 0;
}
