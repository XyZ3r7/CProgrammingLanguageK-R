#include <stdio.h>
#define MAX 30
int main(int argc, char *argv[]) {
  // Create two char array, one for detecting characters until size = max,
  // second array for output the detail in one line
    int c;
    int linelength = 0;
    char cache[MAX + 1];
    char output[MAX + 1];
    int lastSpace = -1;
    while ((c = getchar()) != EOF) {
        cache[linelength++] = c;
        if (c == '\n') {
            cache[linelength] = '\0';
            printf("%s", cache);
            lastSpace = -1;
            linelength = 0;
            continue;
        }
        if (c == ' ') {
            lastSpace = linelength - 1;
        }
        if (linelength == MAX) {
            if (lastSpace == -1) {
                lastSpace = MAX;
          }
            int i;
            for (i = 0; i < lastSpace; i++) {
                output[i] = cache[i];
            }
            output[i] = '\0';
            printf("%s", output);
            putchar('\n');
            int j = 0;
            for (; i < MAX; i++) {
                cache[j] = cache[i];
                j++;
            }
            linelength = j;
            lastSpace = -1;
            int k;
            for (k = 0; k < linelength; k++) {
                if (cache[k] == ' ') {
                    lastSpace = k;
              }
            }
        }

    }
}
