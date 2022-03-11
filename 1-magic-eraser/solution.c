#include <stdio.h>
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", 6*y*y*(x*x*x)/(y*y*y));
}