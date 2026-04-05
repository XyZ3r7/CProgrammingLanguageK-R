#include <stdio.h>
// To test if we finished one line
#define MAXLINE 100

void copy(char to[], char from[]);
int getline1(char s[], int lim);

int main(int argc, char *argv[]) {
    int len; //Current line length
    int max = -1; // Max length so far
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline1(line, MAXLINE)) > 0) {
      // for 1-17 when len > 80, printf("%s", line);
      // for 1-18,another while loop to check if there's space or tab reversely
      // in getline1()
      // for 1-19, same idea as 1-18, another for loop that reverse it.
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

//Return the actual length
int getline1(char s[], int lim) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }

    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }

    if (i >= lim) s[lim - 1] = '\0';
    else s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;

}
