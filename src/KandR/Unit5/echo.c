//
// Created by XyZ3r7 on 8/31/26.
//
#include <stdio.h>

//char *argv[] : every element in this array is a char * (char array/String)
//argv[0] = name of the program.
int main(int argc, char *argv[]) {
    int i;

    for (i = 0; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}