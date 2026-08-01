#include <ctype.h>
#include <stdio.h>
#define  MAXLINE 1000

int getline1(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

//4 - 1
main() {
    char line[MAXLINE];
    int found = 0;

    while (getline1(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

int getline1(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    int index = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k]!= '\0' && s[j] == t[k];j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            index = i;
        }
    }
    return i;
}

// 4 - 2
double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-' ? 0 : 1);
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        int signE = (s[++i] == '-' ? -1 : 1);
        if (s[i] == '-' || s[i] == '+') i++;

        int valE;
        for (valE = 0; isdigit(s[i]); i++)
            valE = 10 * valE + (s[i] - '0');

        while (valE > 0) {
            if (signE) {
                val *= 10;
            }else {
                val /= 10;
            }
            valE--;
        }
    }
    return val;
}
