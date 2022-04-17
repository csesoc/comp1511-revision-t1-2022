#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort_three(double *x, double *y, double *z);
void swap(double *a, double *b);

int main() {
	double x, y, z;
  	
  	scanf("%lf %lf %lf", &x, &y, &z);
  	sort_three(&x, &y, &z);
  	printf("%lf %lf %lf\n", x, y, z);

    return 0;
}

/*
	Takes in three float pointers and sorts the values
    they point to in increasing order.
*/
void sort_three(double *x, double *y, double *z) {
    // 6 possibel combinations for order
    if (x <= y && y <= z) {
        // Case 1: x <= y <= z

        // Start order: x y z
        // No need to swap pointers
    } else if (x <= z && z <= y) {
        // Case 2: x <= z <= y

        // Start order: x y z
        // Swap z and y
        swap(x,y);
        // Order is now: x z y 
    } else if (y <= x && x <= z) {
        // Case 3: y <= x <= z
        
        // Start order: x y z
        // Swap x and y
        swap(x,y);
        // Order is now: y x z
    } else if (y <= z && z <= x) {
        // Case 4: y <= z <= x

        // Start order: x y z
        // Swap x and z
        swap(x,z);
        // Order is now: z y x

        // Swap z and y
        swap(y, z);
        // Order is now: y z x
    } else if (z <= x && x <= y) {
        // Case 5: z <= x <= y

        // Start order: x y z
        // Swap x and y
        swap(x,y);
        // Order is now: y x z

        // Swap y and z
        swap(y,z);
        // Order is now: z x y
    } else {
        // Case 6: z <= y <= x

        // Start order: x y z
        // Swap x and z
        swap(x,z);
        // Order is now: z y x
    }
}

/*
	Swaps the values in two floats, given as pointers
*/
void swap(double *a, double *b) {
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}