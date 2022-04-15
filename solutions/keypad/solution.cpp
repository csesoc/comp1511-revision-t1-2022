#include <cstdio>

int N, r, c;
char S[105];
int grid[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

int main() {
    scanf("%d", &N);
    scanf(" %s", S);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'P') printf("%d", grid[r][c]);
        if (S[i] == 'L') c--;
        if (S[i] == 'R') c++;
        if (S[i] == 'U') r--;
        if (S[i] == 'D') r++;
    }
    printf("\n");
}