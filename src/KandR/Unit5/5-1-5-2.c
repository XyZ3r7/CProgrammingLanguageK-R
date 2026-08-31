#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);
int getfloat(float *pn);

int main(int argc, char *argv[]) {
    // int pn;
    // printf("status code for getint is: %d\n",getint(&pn));
    // printf("Integer you entered was: %d\n", pn);
    float pn1;
    printf("status code for getint is: %d\n",getfloat(&pn1));
    printf("Integer you entered was: %f\n", pn1);
    return 0;
}


/* getint: get next integer from input into *pn*/
int getint(int *pn) {
    int c, sign;
    int result;
    while (isspace(c = getch())) // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            if (sign + 1) ungetch('+');
            else ungetch('-');
            return -2;
        }
    }
    for (result = 0; isdigit(c); c = getch())
        result = 10 * result + (c - '0');
    result *= sign;
    *pn = result;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
//5-2
int getfloat(float *pn) {
    float sign;
    int c;
    float resultI, resultF;
    while (isspace(c = getch())) // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            if (sign + 1) ungetch('+');
            else ungetch('-');
            return -2;
        }
    }
    //Process the integer part
    for (resultI = 0; isdigit(c); c = getch())
        resultI = 10 * resultI + (c - '0');
    if (c == '.') {
        c = getch();
        float power = 1.0;
        for (resultF = 0; isdigit(c); c = getch()) {
            resultF = 10 * resultF + (c - '0');
            power *= 10.0;
        }
        resultF /= power;
        *pn = (resultI + resultF) * sign;
        ungetch(c);
        return c;
    }
    *pn = resultI * sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

