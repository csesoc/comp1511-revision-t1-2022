// N^5 bruteforce
#include <stdio.h>
#define MAXN 100010
typedef long long ll;
int n, r[MAXN];
ll h[MAXN];
ll ans = 1e18;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
	for (int i = 0; i < n; i++) scanf("%d", &r[i]);
	for (int left = 0; left < n; left++) {
		for (int s = left; s < n; s++) {
			for (int e = s; e < n; e++) {
				for (int right = e; right < n; right++) {
					// Path starts at s, goes to left, then to right, then to e

					// Walk onto s
					ll dis = h[s]*h[s];

					// Walk from s to left
					for (int i = left; i < s; i++) {
						dis += (h[i]-h[i+1])*(h[i]-h[i+1]);
					}

					// Walk from left to right
					for (int i = left; i < right; i++) {
						dis += (h[i]-h[i+1])*(h[i]-h[i+1]);
					}

					// Walk from right to end
					for (int i = e; i < right; i++) {
						dis += (h[i]-h[i+1])*(h[i]-h[i+1]);
					}

					// Walk off the end
					dis += h[e]*h[e];

					int reward = 0;
					for (int i = left; i <= right; i++) {
						reward += r[i];
					}

					if (reward >= 1 && dis < ans) {
						ans = dis;
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
}
