// Solution by Angus
#include <stdio.h>
#define MAXN 110
int n, p[MAXN], is_unknown[MAXN], pre = 100, sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		if (p[i] == -1) {
			p[i] = pre;
			is_unknown[i] = 1;
		}
		pre = p[i];
		sum += p[i];
	}

	pre = 1;
	for (int i = n-1; i >= 0; i--) {
		while (is_unknown[i] && sum > 100 && p[i] > pre) {
			p[i]--;
			sum--;
		}
		pre = p[i];
	}

	if (sum == 100) {
		for (int i = 0; i < n; i++) printf("%d ", p[i]);
		printf("\n");
	} else {
		for (int i = 0; i < n; i++) printf("%d ", -1);
		printf("\n");
	}
}
