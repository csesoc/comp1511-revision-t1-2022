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
    // Determine the smallest element and store into x
    if (x > z) {
        swap(x, z);
    }
   
    if (x > y) {
        swap(x, y);
    }

    // Now the smallest element is stored into x
    // Compare the remaining two elements 
    if (y > z) {
        swap(y, z);
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