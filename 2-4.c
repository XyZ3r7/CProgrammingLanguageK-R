#include <stdio.h>

#define FOUND 1
#define NOT_FOUND 0
void squeeze2(char s1[], char s2[]);
int main(int argc, char *argv[]) { return 0; }

void squeeze2(char s1[], char s2[]) {
    int i, j, k = 0;
    int state = NOT_FOUND;
    for (i = j = 0; s1[i] != '\0'; i++) {
        state = NOT_FOUND;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                state = FOUND;
                break;
            }
        }
        if (state) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
