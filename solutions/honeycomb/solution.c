#include <stdio.h>

// T(n) is the n-th triangular number.
int T(int n) {
    // From maths, 1 + 2 + ... + n = n * (n+1) / 2.
    return n * (n+1) / 2;
}

int main() {
    int A, B, C, D, E, F;
    scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);

    int triangle_side = A + B + F - 2;
    // Alternatively, B+C+D-2 or D+E+F-2 also give the same result

    printf("%d\n", T(triangle_side) - T(B-1) - T(D-1) - T(F-1));
}