//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    int x = 0;
    printf("Please enter the value for x:");
    scanf("%d", &x);
    printf("The value for 3*x^5 + 2x^4 - 5x^3 -x^2 + 7x - 6 is: %d\n",
        3 * x * x * x * x * x + 2 * x * x * x *x - 5 * x * x * x - x * x + 7 * x - 6);

    //Horner's Rule
    printf("The value for 3*x^5 + 2x^4 - 5x^3 -x^2 + 7x - 6 is: %d\n",
        ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);

}