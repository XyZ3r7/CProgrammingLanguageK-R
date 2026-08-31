//
// Created by XyZ3r7 on 5/4/26.
//
#include <stdio.h>
int main() {
    return 0;
}

unsigned getBits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

//I searched up how to do this bit operations.
unsigned setBits(unsigned x, int p, int n, unsigned y) {
    //Constructing mask to clear target bits for x

    unsigned mask = ~(~(~0 << n) << (n - 1 + p));

    //Clear the wanted bits of x
    unsigned clearedX = x & mask;

    //NO another ~ clear the part other than wanted to 0 and move them to the wanted place for x
    unsigned yBits = (y & ~0 << n) << (n -1 + p);

    return clearedX | yBits;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = (~(~0 << n) << (p + 1 - n));
    //Clear the wanted part first
    unsigned clearedX = x & ~mask;
    //Clear the part where doesn't want to be inverted as y
    unsigned invert = (~(x) & mask);
    return clearedX | invert;
}

//Solution given by Gemini
unsigned invert2(unsigned x, int p, int n) {
    unsigned mask = (~(~0 << n)) << (p + 1 - n);
    return x ^ mask;
}

unsigned rightRot(unsigned x, int n) {
    unsigned mask = ~(~0 << n);
    unsigned shifted = x & mask;
    x = x >> n;
    shifted = shifted << ((sizeof(unsigned) * 8) - n);
    return x | shifted;
}
