#include <stdio.h>

int main() {
    int c = getchar();
    printf("%d\n", c != EOF);//Always 1 unless terminal sends EOF signal(MacOS/Linux: Ctrl + D, Windows: Ctrl + Z)
    return 0;
}
