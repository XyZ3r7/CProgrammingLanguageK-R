//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main(void)
{
    int start, middle, end;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &start, &middle, &end);

    printf("You entered %d.%d.%d\n", start, middle, end);

    return 0;
}