#include <stdio.h>
#define DELETE 0
#define NONDELETE 1
// Situation I want to handle: comments in "", which is in NONDELETE Mode
// comments in Delete Mode
// inside of comments, I have to ignore "".
int main(int argc, char *argv[]) {
    int c;
    int prevC = -1;
    int state = NONDELETE;
    int stateLock = 0;
    int commentType1 = 0;
    int commentType2 = 0;
    int justEndedComment = 0;
    int escaped = 0;
    while ((c = getchar()) != EOF) {
      // Key idea is to find out enters which state first, if meet //,
      // /**/first, enter DELETE state, if meet " first, enter NONDELETE
      // State Switching when encounter ""
      // Since it's always read form top to bottom, if I read out // or /**/, I
      // can always delete them,
      // if I meet "", I can just continue output and ignore //



      // Logic for choosing state
        if (stateLock != 1) {
            if (c == '/' && prevC == '/') {
                commentType1 = 1;
                stateLock = 1;
                state = DELETE;
            } else if (c == '*' && prevC == '/') {
                commentType2 = 1;
                stateLock = 1;
                state = DELETE;
            } else if (c == '"') {
                escaped = 0;
                stateLock = 1;
                state = NONDELETE;
            }
        } else {
            if ((commentType1 || commentType2) && (state == DELETE)) {
                if (commentType1 && c == '\n') {
                    stateLock = 0;
                    commentType1 = 0;
                    state = NONDELETE;
                }else if (c == '/' && prevC == '*' && commentType2) {
                    stateLock = 0;
                    commentType2 = 0;
                    justEndedComment = 1;
                    state = NONDELETE;
                }
            } else if (state == NONDELETE && c == '"') {
                //I forgot to consider this one.
                if (!escaped) {
                    stateLock = 0;
                    state = NONDELETE;
                }
            }

        }

        if (state != DELETE) {
            if (prevC != -1) {
                if (justEndedComment) {
                    justEndedComment = 0;
                }else if (c != '/' && prevC != '/') {
                    putchar(prevC);
                }
            }
        }

        if (stateLock == 1 && state == NONDELETE) {
            if (c == '\\') {
                escaped = !escaped;
            } else {
                escaped = 0;
            }
        }
        prevC = c;
    }
    putchar(prevC);
    return 0;
}
