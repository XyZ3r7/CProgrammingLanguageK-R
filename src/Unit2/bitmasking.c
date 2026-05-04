#include <stdio.h>
//
// Created by XyZ3r7 on 5/4/26.
//
int main() {
    unsigned int num = 103;
    unsigned int mask = ~((1 << 0) | (1 << 2) | (1 << 3));

    num = num & mask;

    num = num & mask;

    printf("Result: %u\n", num);

    return 0;
}