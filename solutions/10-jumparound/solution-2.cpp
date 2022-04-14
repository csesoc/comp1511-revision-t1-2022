#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
#define MAXN 100010
int n, x[MAXN], ans, seen[MAXN], a[MAXN], b[MAXN];
vector<int> adj[MAXN];
int dfs(int a) {
	if (seen[a]) return 0;
	seen[a] = 1;
	int occ = 0;
	for (int b : adj[a]) {
		occ += dfs(b);
	}
	if (a) {
		ans += occ;
		occ = max(1, x[a]-occ);
		ans += occ;
		return occ;
	} else {
		ans += occ;
		ans += 2*max(0, x[a]-occ-1)+1;
		return 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 1; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) scanf("%d", &b[i]);
	for (int i = 1; i < n; i++) {
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	assert(!dfs(0));
	printf("%d\n", ans);
}