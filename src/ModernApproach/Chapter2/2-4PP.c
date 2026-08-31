//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>

int main()
{
    float amount = 0;
    printf("Enter an amount: ");
    scanf("%f", &amount);
    printf("With tax added: %.2f\n", 1.05 * amount);

    return 0;
}