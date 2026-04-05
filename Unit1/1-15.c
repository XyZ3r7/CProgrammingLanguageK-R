#include <stdio.h>

void calculate(int lower, int upper, int step);
int main() {
    calculate(0, 300, 20);
    return 0;
}

void calculate(int lower, int upper, int step) {
    int fahr = lower;
    int celsius;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
