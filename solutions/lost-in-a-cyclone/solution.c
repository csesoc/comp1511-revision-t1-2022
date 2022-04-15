#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int main(void) {
    int n = 0;
    int t = 0;
    int power_x = pow(2, 0);
    int power_y = pow(2, 0);
    float cos10t = cos(0);
    float sin10t = sin(0);
    int array[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {0};

    scanf("%d", &n);

    while (t <= n) {
        //x value calcularing
        power_x = pow(2, t);
        cos10t = cos(10 * t);
        float power_x_float = power_x;
        int x_value = round(power_x_float * cos10t);

        //y value calcularing
        power_y = pow(2, t);
        sin10t = sin(10 * t);
        float power_y_float = power_y;
        int y_value = round(power_y_float * sin10t);

        //z value calcularing
        int z_value = t;

        array[t][x_value+15][y_value+15][z_value+15] = 1;
        t++;
    }

    //printing out the values, using the government's computer.
    int x = 0;
    int y = 0;
    int z = 0;
    t = 0;
    while (t < MAX_SIZE) {
        while (z < MAX_SIZE) {
            while (y < MAX_SIZE) {
                while (x < MAX_SIZE) {
                    if (array[t][x][y][z] == 1) {
                        printf("(%d, %d, %d) at %d seconds\n", x-15, y-15, z-15, t);
                    }
                    x++;
                }
                x = 0;
                y++;
            }
            y = 0;
            z++;
        }
        z = 0;
        t++;
    }
    return 0;
}
