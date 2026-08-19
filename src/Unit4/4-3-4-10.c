//
// Created by XyZ3r7 on 8/1/26.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

// reverse polish calculator
int main() {
    int type;
    double op2;
    char s[MAXOP];
    int var;
    double variables[26] = {0};
    double v = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case '=':
                if (var >= 'A' && var <= 'Z') {
                    pop();
                    variables[var - 'A'] = pop();
                }else {
                    printf("no variable name\n");
                }
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) push(pop() / op2);
                else printf("Error: zero divisor\n");
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '%':
                op2 = pop();
                double op1 = pop();
                if (op2 == 0.0) {
                    printf("error: zero divisor\n");
                    break;
                }
                int sign = (op1 < 0) ? -1 : 1;
                if (op1 < 0) op1 = -op1;
                while (op1 > op2)
                    op1-=op2;
                push(sign * op1);
                break;
            case 'n':
                if (strcmp(s, "sin") == 0) push(sin(pop()));
                else if (strcmp(s, "cos") == 0) push(cos(pop()));
                else if (strcmp(s, "exp") == 0) push(exp(pop()));
                else if (strcmp(s, "pow") == 0){ op2 = pop(); push(pow(pop(), op2));}
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variables[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("stack full");
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty \n");
        return 0.0;
    }
}

double peek() {
    return val[sp - 1];
}

#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    /*
     *  returns the type of the operator/number;
     */
    if (isalpha(c)) {
        while (isalpha(s[++i] = c =getch()))
            ;
        s[i] = '\0';
        if (c != EOF) ungetch(c);
        if (strlen(s) > 1) return 'n';
        else return s[0];
    }
    if (!isdigit(c) && c != '.')  return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0'; if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
int buf = 0;
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */ {
    int c;
    if (buf != 0) {
        c = buf;
        buf = 0;
    }else
        c = getchar();
    return c;
}
void ungetch(int c) /* push character back on input */ {
    if (bufp != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}

//4-7
void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

//4-10
#define MAXLINE 100
char line[MAXLINE];
int lp = 0;

int get_line(char s[], int lim);

int getop1(char s[]) {
    int i, c;

    while (line[lp] == '\0') {
        if (get_line(line, MAXLINE) == 0)
            return EOF;
        lp = 0;
    }

    while ((s[0] = c = line[lp++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    if (isalpha(c)) {
        while (isalpha(s[++i] = c = line[lp++]))
            ;
        s[i] = '\0';
        lp--;
        return (strlen(s) > 1) ? 'n' : s[0];
    }
    if (!isdigit(c) && c != '.') return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[lp++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[lp++]))
            ;
    s[i] = '\0';
    lp--;
    return NUMBER;
}

int get_line(char s[], int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}