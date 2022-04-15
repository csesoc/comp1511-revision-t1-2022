// Solution by Joseph
#include <stdio.h>
 
int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	printf("%d\n", (f+a+b-2)*(f+a+b-1)/2
                    -(f-1)*f/2
                    -(b-1)*b/2
                    -(d-1)*d/2
	);
}
