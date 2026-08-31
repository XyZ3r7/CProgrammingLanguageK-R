//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    int GS1, groupIdentifier,publisherCode,itemNumber, checkDigit;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &GS1, &groupIdentifier, &publisherCode, &itemNumber, &checkDigit);
    printf("GS1 prefix: %d\n"
           "Group identifier: %d\n"
           "Publisher code: %d\n"
           "Item number: %d\n"
           "Check digit: %d\n", GS1, groupIdentifier, publisherCode, itemNumber, checkDigit);

    return 0;
}