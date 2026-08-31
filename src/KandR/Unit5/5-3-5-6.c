//
// Created by XyZ3r7 on 8/18/26.
//
#include <stdio.h>
//5-4 Alloc example
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; //Next free position

char *alloc(int n) {
    /*allocbuf + Allocsize - allocp = size of rest spaces because allocbuf and alloccp
     *because if allocbuf stands for starting location of array, alloccp will be "offset",
     *So Allocbuf - allocp must = size used.
     */
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; //Old pointer
    } else {
        return 0;
    }
}

void afree(char *p) {
    //Check if the address is within range
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

//Strlen
int strlen(char *s) {
    char *p = s;

    while (*p != '\0') {
        p++;
    }
    //Because p++ add one size of char and both of them are char.
    return p - s;
}

//5-5
//points to a String constant
static char *pmessage = "now is the time";
//points to an array: able to change the array.
static char amessage[] = "now is the time";

//strcpy: copy t to s; array subscript version
void strcpy(char *s, char *t) {
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0') //doesn't seem safe
        i++;
}

//strcpy2: copy t to s; pointer version
void strcpy2(char *s, char *t) {
    //return non 0
    //this = returns the value just copied
    while ((*s++ = *t++))
        ;
}

//strcmp
int strcmp(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    //return the difference in ASCII value between first different character
    return s[i] - t[i];
}

//strcmp pointer version
//I implemented this.
int strcmpp(char *s, char *t) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

//5-3
void strcat(char *s, char *t) {
    int lengthS = strlen(s);
    s += lengthS;
    while ((*s = *t)) {
        s++;
        t++;
    }
}
//5-4
int strend(char *s, char *t) {
    int lengthS = strlen(s);
    s += lengthS - strlen(t);
    while (*s == *t) {
        if (*t == '\0') return 1;
        s++;
        t++;
    }
    return 0;
}

//5-5
void strncpy(char *s, char *t, int n) {
    while (n-- > 0 && ((*s = *t))) {
        s++;
        t++;
    }
}

void strncat(char *s, char *t, int n) {
    int lengthS = strlen(s);
    s += lengthS;
    while (n-- > 0 && ((*s = *t))) {
        s++;
        t++;
    }
}

int strncmp(char *s, char *t, int n) {
    for ( ;n-- > 0 && *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

//5-6 One day I will do them.

