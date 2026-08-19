//
// Created by XyZ3r7 on 8/5/26.
//
#include <stdio.h>
int main(void) {

}

//4 - 12
static int itoa_r(int n, char s[], int i) {
    if (n / 10)
        i = itoa_r(n / 10, s, i);
    s[i++] = n % 10 + '0';
    return i;
}

//4 - 13
static void reverse_r(char s[], int i, int j) {
    char c;
    if (i < j) {
        c = s[i]; s[i] = s[j]; s[j] = c;
        reverse_r(s, i + 1, j - 1);
    }
}