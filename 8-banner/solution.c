// dp solution
#include <stdio.h>
#define MAXN 100010
int dp[MAXN][3][3], str[MAXN], n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'I') str[i] = 0;
		else if (c == 'M') str[i] = 1;
		else if (c == 'C') str[i] = 2;
		else str[i] = 3;
	}
	for (int i = n-1; i >= 0; i--) {
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				for (int c = 0; c < 3; c++) {
					if (str[i] < 3 && str[i] != c) {
						continue;
					}
					int am = dp[i+1][b][c];
					if (a == 0 && b == 1 && c == 2) am++;
					if (am > dp[i][a][b]) dp[i][a][b] = am;
				}
			}
		}
	}
	printf("%d\n", dp[0][2][2]);
}