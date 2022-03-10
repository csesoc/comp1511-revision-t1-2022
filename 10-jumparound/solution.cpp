#include <cstdio>
#include <vector>
using namespace std;

int N, X[100005], A[100005], B[100005], ans = 0;
vector<int> adj[100005];
void dfs(int u, int prev = -1) {
	ans++;
	X[u]--;
	for (int v: adj[u]) if (v != prev) {
		dfs(v, u);
		if (X[v] > 0) {
			ans += 2 * X[v];
			X[u] -= X[v];
		}
		ans++;
		X[u]--;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	for (int i = 0; i < N-1; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N-1; i++) {
		scanf("%d", &B[i]);
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	dfs(0, -1);
	if (X[0] > 0) {
		//fprintf(stderr, "lol\n");
		ans += X[0] * 2;
	}
	printf("%d\n", ans);
}