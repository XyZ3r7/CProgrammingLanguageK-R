//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    int day = 0, month = 0, year = 0;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %d%d%d\n", year, month, day);

    return 0;
}