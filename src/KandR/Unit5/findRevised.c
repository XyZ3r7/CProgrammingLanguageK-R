//
// Created by XyZ3r7 on 8/31/26.
//
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    //++argv points to next parameter
    //（*++argv) takes the address of char * argv[]
    // (*++argv)[0] takes the char array at next address
    // *++argv[0] = takes the char inside.
    while (--argc > 0 && (*++argv)[0] == '-'){
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1) printf("Usage: find -x -n pattern\n");
    else {
        while (getline1(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
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

