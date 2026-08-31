//
// Created by XyZ3r7 on 8/31/26.
//
#include <stdio.h>
int main(void) {
    int height = 8, length = 12, width = 10, volume = height * length * width, weight = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\nVolume (cubic inches): %d\nDimensional weight (pounds): %d\n", length, width, height,volume,weight);

    return 0;
}