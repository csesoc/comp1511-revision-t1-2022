// Second full solution, by Angus
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int n, ans, pre[MAXN][4]; // u, d, l, r
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char a;
		scanf(" %c", &a);
		if (a == 'U') pre[i][0]++;
		else if (a == 'D') pre[i][1]++;
		else if (a == 'L') pre[i][2]++;
		else if (a == 'R') pre[i][3]++;
		else assert(false);
		for (int j = 0; j < 4; j++) pre[i][j] += pre[i-1][j];
	}
	for (int i = 1; i <= n; i++) {
		int ydis = max(min(pre[i][0], pre[n][1]-pre[i][1]), min(pre[i][1], pre[n][0]-pre[i][0]));
		int xdis = max(min(pre[i][2], pre[n][3]-pre[i][3]), min(pre[i][3], pre[n][2]-pre[i][2]));
		ans = max(ans, xdis+ydis);
	}
	printf("%d\n", ans);
}