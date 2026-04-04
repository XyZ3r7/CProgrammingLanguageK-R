#include <stdio.h>

int main() {
    printf("This program is for printing out the value for EOF\n");
    int c = getchar();
    if (c == EOF) {
        printf("%d", c);
    }
    return 0;
}
