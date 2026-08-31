#include <stdio.h>

int main() {
    int space = 0;
    int tab = 0;
    int enter = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++space;
        } else if (c == '\t') {
            ++tab;
        } else if (c == '\n') {
            ++enter;
        }
    }

    printf("# of space: %d, tab: %d, enter: %d\n", space, tab, enter);
    return 0;
}
