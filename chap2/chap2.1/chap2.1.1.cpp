#include<stdio.h>
int main()
{
    int count = 0;
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            if (3 * x + 4 * y == 16) {
                printf("x = %d y = %d\n", x, y);
                count ++;
            }
        }
    }
    printf("Total Count: %d\n", count);
    return 0;
}