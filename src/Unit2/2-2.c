#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, c;
    int limit = 10;
    for (i = 0; i < limit && (c = getchar()) != '\n' && c != EOF; ++i) {
    }

    while (i < limit) {
        if ((c = getchar()) == '\n') {
            break;
        } else if (c == EOF) {
            break;
        }
    }
    return 0;
}
