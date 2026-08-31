//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    int numOf20 = 0, numOf10 = 0, numOf5 = 0, numOf1 = 0;
    int amount = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    numOf20 = amount / 20;
    numOf10 = (amount - numOf20 * 20) / 10;
    numOf5 = (amount - numOf20 * 20 - numOf10 * 10) / 5;
    numOf1 = (amount - numOf20 * 20 - numOf10 * 10 - numOf5 * 5);
    printf("$20 bills: %d\n"
           "$10 bills: %d\n"
           "$5 bills: %d\n"
           "$1 bills: %d\n", numOf20, numOf10, numOf5, numOf1);
    return 0;
}