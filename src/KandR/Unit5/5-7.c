//
// Created by XyZ3r7 on 8/18/26.
//
//5-7 example
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
#define MAXLEN 1000
int readlines(char *lineptr[], int nlines, char oneLine[MAXLINES][MAXLEN]);
// int readlines(char *lineptr[], int nlines);

//5-7
//practice version is slower than original version.!!!!!!!!!!!!!!!

/* sort input lines */
int main() {
    clock_t start = clock();
    char oneLine[MAXLINES][MAXLEN];
    int nlines;
    // if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
    if ((nlines = readlines(lineptr, MAXLINES, oneLine)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        // return 0;
    }else {
        printf("error: input too big to sort\n");
        return 1;
    }
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("耗时: %f 秒\n", elapsed);
    return 0;
}

#define MAXLEN 1000 // Max length of any input line
int getline1(char *, int);
char *alloc(int);

int getline1(char *line, int maxlen) {
    int c, i;
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

// read input lines
  // int readlines(char *lineptr[], int maxlines) {
  //     int len, nlines;
  //     char *p, line[MAXLEN];
  //     nlines = 0;
  //     //assign a area for p for inputting content in one line,
  //     //then let element in lineptr[] points to that area;
  //     while ((len = getline1(line,MAXLEN)) > 0) {
  //         if ((nlines >= maxlines || ((p = alloc(len)) == NULL))) {
  //             return -1;
  //         }else {
  //             line[len - 1] = '\0'; //Delete newline
  //             strcpy(p, line);
  //             lineptr[nlines++] = p;
  //         }
  //     }
  //     return nlines;
  // }

int readlines(char *lineptr[], int maxlines, char oneLine[MAXLINES][MAXLEN]) {
    int len;
    int nlines = 0;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) return -1;
        else {
            line[len - 1] = '\0';
            strcpy(oneLine[nlines], line);
            lineptr[nlines] = oneLine[nlines];
            nlines++;
        }
    }
    return nlines;
}

//writelines: write output lines
void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);

}

void swap(char *v[], int i, int j);
//qsort: sort v[left] ... v[right] into increasing order
void qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right) //do nothing if array contains fewer than two elements
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}