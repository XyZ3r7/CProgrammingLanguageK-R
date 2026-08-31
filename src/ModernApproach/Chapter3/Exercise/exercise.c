//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    printf("%12.5e\n", 30.253);
    //.2 means round to 2 valid numbers, therefore 0.0000009979 -> 0.00000010 -> to e = 1e-06
    printf("%-6.2g\n", .0000009979);

    return 0;
}