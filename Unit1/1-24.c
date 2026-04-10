#include <stdio.h>
// Inorder to check if there's right number of bracket, I have to check if
// there's equal numeber of bracket combo
// And I need to ignore the part in comments and "" and escape sequences
void normalProcessor(int c);
void abnormalProcessor(int c);
int small = 0;
int middle = 0;
int large = 0;

// Yeah, I know, state machine
#define NORMAL 0
#define ESCAPE 1
#define LINE_COMMENT 2
#define STAR_COMMENT 3
#define QUOTATIONMARKS 4
int main(int argc, char *argv[]) {
  // Two cases, when brackets does count and brackets does not counts, clearly
  // when not in NORMAL mode brackets does NOT count

    int state = NORMAL;
    int prevState = state;
    int c, prevC = -1;
    while ((c = getchar()) != EOF) {
        if (state == NORMAL) {
            if (c == '\\') {
                prevState = NORMAL;
                state = ESCAPE;
            } else if (c == '/' && prevC == '/') {
                prevState = NORMAL;
                state = LINE_COMMENT;
            } else if (c == '*' && prevC == '/') {
                prevState = NORMAL;
                state = STAR_COMMENT;
            } else if (c == '"') {
                prevState = NORMAL;
                state = QUOTATIONMARKS;
            }
        } else {
            // See if I can end STATE
            if (state == ESCAPE) {
                state = prevState;
                continue;
            } else if (state == LINE_COMMENT) {
                if (c == '\n') {
                    prevState = state;
                    state = NORMAL;
                }
            }else if (state == STAR_COMMENT) {
                if (c == '/' && prevC == '*') {
                    prevState = state;
                    state = NORMAL;
              }
            } else if (state == QUOTATIONMARKS) {
                if (c == '"') {
                    prevState = state;
                    state = NORMAL;
                } else if (c == '\\') {
                    prevState = state;
                    state = ESCAPE;
                }

            }
        }

        switch (state) {
            case NORMAL:
                normalProcessor(c);
                break;
            case ESCAPE:
            case LINE_COMMENT:
            case STAR_COMMENT:
            case QUOTATIONMARKS:
                abnormalProcessor(c);
                break;
        }
    }
    if (small > 0 || small < 0) {
        printf("You are missing small brackets");
    }
    if (middle > 0 || middle < 0) {
        printf("You are missing middle brackets ");
    }
    if (large > 0 || large < 0) {
        printf("You are missing large brackets");
    }
    if (state == QUOTATIONMARKS) {
        printf("You must be missing some quotation marks");
    }
    if (state == STAR_COMMENT) {
        printf("You did not close the star comments");
    }
    return 0;
}

void normalProcessor(int c) {
    switch (c) {
        case '(':
            small++;
            break;
        case ')':
            small--;
            break;
        case '[':
            middle++;
            break;
        case ']':
            middle--;
            break;
        case '{':
            large++;
            break;
        case '}':
            large--;
            break;
    }
}
