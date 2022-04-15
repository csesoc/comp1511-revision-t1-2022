// Solution by Angus
// Should output a different answer to the other solution, but still correct
#include <stdio.h>
#define MAXN 110
int n, p[MAXN], is_unknown[MAXN], pre = 1, sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = n-1; i >= 0; i--) {
		if (p[i] == -1) {
			p[i] = pre;
			is_unknown[i] = 1;
		}

		sum += p[i];
		pre = p[i];
	}

	while (sum < 100) {
		int done = 0;
		for (int i = n-1; i >= 0; i--) {
			if (is_unknown[i] && (i == 0 || p[i] < p[i-1])) {
				p[i]++;
				sum++;
				done = 1;
				break;
			}
		}
		if (!done) {
			for (int i = 0; i < n; i++) printf("%d ", -1);
			printf("\n");
			return 0;
		}
	}

	if (sum == 100) {
		for (int i = 0; i < n; i++) printf("%d ", p[i]);
		printf("\n");
	} else {
		for (int i = 0; i < n; i++) printf("%d ", -1);
		printf("\n");
	}
}
