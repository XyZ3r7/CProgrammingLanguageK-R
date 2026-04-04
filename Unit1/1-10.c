#include <stdio.h>
#define normal 0
#define special 1
int main() {
    int c;
    int state;

    /*
     * I just want to try this state machine
     */

    /*
    while ((c = getchar()) != EOF){
        if(c != '\t' && c != '\\' && c != '\b'){
            state = normal;
        } else {
            state = special;
        }

        if (state) {
            if (c == '\t') {
                putchar('\\');
                putchar('t');
            } else if (c == '\b') {
                putchar('\\');
                putchar('b');
            } else {
                putchar('\\');
            }
        } else {
            putchar(c);
        }
    }
    */

    /*
     * High Performance state machine
     */

    while((c = getchar() != EOF)){
            switch (c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            }
    }

    return 0;
}
