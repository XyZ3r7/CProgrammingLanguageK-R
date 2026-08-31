//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    int i;
    float x;

    i = 40;
    x = 839.21f;

    //e displays a floating points in exponential format(scientific notation)
    //g displays a floating points either in exponential format or fixed format depends on the size
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

    return 0;
}
