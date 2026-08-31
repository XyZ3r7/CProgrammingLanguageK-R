//
// Created by XyZ3r7 on 8/31/26.
//
#include <stdio.h>
int main() {
    int row00 = 0, row01 = 0, row02 = 0, row03 = 0;
    int row10 = 0, row11 = 0, row12 = 0, row13 = 0;
    int row20 = 0, row21 = 0, row22 = 0, row23 = 0;
    int row30 = 0, row31 = 0, row32 = 0, row33 = 0;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &row00,&row01,&row02,&row03,
        &row10,&row11,&row12,&row13,
        &row20,&row21,&row22,&row23,
        &row30,&row31,&row32,&row33);

    //So funny hh

    printf("%4d%4d%4d%4d\n"
           "%4d%4d%4d%4d\n"
           "%4d%4d%4d%4d\n"
           "%4d%4d%4d%4d\n", row00, row01, row02, row03, row10,row11,row12,row13,row20,row21,row22,row23,row30,row31,row32,row33);
    printf("Row sums: %d %d %d %d\n", row00 + row01 + row02 + row03, row10 + row11 + row12 + row13, row20 + row21 + row22 + row23, row30 + row31 + row32 + row33);
    printf("Column sums: %d %d %d %d\n", row00 + row10 + row20 + row30, row01 + row11 + row21 + row31, row02 + row12 + row22 + row32, row03 + row13 + row23 + row33);
    printf("Diagonal sums: %d %d\n", row00 + row11 + row22 + row33, row03 + row12 +row21 + row30);
}
