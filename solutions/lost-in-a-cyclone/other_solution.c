#include <stdio.h>
#include <math.h>

int main(void) {
    int seconds;
    scanf("%d", &seconds);

    int t = 0;
    while (t <= seconds) {
        int x = round(pow(2, t) * cos(10 * t));
        int y = round(pow(2, t) * sin(10 * t));
        int z = t;

        printf("(%d, %d, %d) at %d seconds\n", x, y, z, t);
        t++;
    }

    return 0;
}