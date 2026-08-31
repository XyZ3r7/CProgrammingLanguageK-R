//
// Created by xyz3r7 on 5/18/26.
//
#include <stdio.h>

int main() {
    int c = 0;
    while ((c = getchar()) != '\0') {
        putchar((c >= 'A' && c <= 'Z') ? (c + 32) : c);
    }
    return 0;
}