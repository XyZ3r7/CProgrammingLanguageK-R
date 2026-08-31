//
// Created by xyz3r7 on 8/31/26.
//
#include <iso646.h>
#include  <stdio.h>
int main()
{
    int itemNumber = 0;
    float unitPrice = 0.0;
    int day = 0, month = 0, year = 0;
    printf("Enter item number:\n");
    scanf("%d", &itemNumber);
    printf("Enter unit price:\n");
    scanf("%f", &unitPrice);
    printf("Enter a date (mm/dd/yyyy): \n");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\t\t\tUnit\t\t\t\tPurchase\n"
           "\t\t\t\tPrice\t\t\t\tDate\n"
           "%d\t\t\t\t%$6.2f\t\t\t\t%d/%d/%d\n", itemNumber, unitPrice, month, day, year);

    return 0;
}