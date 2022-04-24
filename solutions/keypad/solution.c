#include <stdio.h>

int main(void)
{
    int N;
    char S[128];
    int x = 1;
    
    scanf("%d %s", &N, S);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') x -= 1;
        if (S[i] == 'R') x += 1;
        if (S[i] == 'U') x -= 3;
        if (S[i] == 'D') x += 3;
        if (S[i] == 'P') printf("%d", x);
    }
}