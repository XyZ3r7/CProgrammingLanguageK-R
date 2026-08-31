//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    printf("Please enter the radius: ");
    int radius = 0;
    scanf("%d", &radius);
    printf("The volume of a sphere with %d meter(s) radius is: %f.\n", radius, 4./3. * 3.1415926 * radius);
    //If we are using 4/3 then there will be a conversion loss.
}