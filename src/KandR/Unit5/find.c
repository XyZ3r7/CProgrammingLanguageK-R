//
// Created by XyZ3r7 on 8/31/26.
//
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int getline1(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;
    if (argc != 2) printf("Usage: find pattern\n");
    else
        while (getline1(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    return found;
}

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