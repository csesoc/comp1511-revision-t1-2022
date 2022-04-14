#include <bits/stdc++.h>
using namespace std;
#define MAXN 110
int grid[MAXN][MAXN], r, c, n;
bool allowed[MAXN][MAXN], seen[MAXN][MAXN];
struct UF {
	pair<int, int> rep[MAXN][MAXN];
	int sz[MAXN][MAXN];
	UF() {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				rep[i][j] = { i, j };
				sz[i][j] = 1;
			}
		}
	}
	pair<int, int> findrep(pair<int, int> a) {
		if (rep[a.first][a.second] == a) return a;
		return rep[a.first][a.second] = findrep(rep[a.first][a.second]);
	}
	void merge(pair<int, int> a, pair<int, int> b) {
		a = findrep(a);
		b = findrep(b);
		if (a != b) {
			rep[b.first][b.second] = a;
			sz[a.first][a.second] += sz[b.first][b.second];
		}
	}
	int getSize(pair<int, int> a) {
		a = findrep(a);
		return sz[a.first][a.second];
	}
};

UF uf;
int numSeen;
void dfs(int x, int y) {
	if (numSeen == n) return;
	if (seen[x][y]) return;
	seen[x][y] = 1;
	numSeen++;
	if (allowed[x-1][y]) dfs(x-1, y);
	if (allowed[x+1][y]) dfs(x+1, y);
	if (allowed[x][y-1]) dfs(x, y-1);
	if (allowed[x][y+1]) dfs(x, y+1);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	vector<array<int, 4>> sortedCells;

	scanf("%d%d%d", &r, &c, &n);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			scanf(" %c", &c);
			grid[i][j] = c - '0';
			sortedCells.push_back({grid[i][j], uniform_int_distribution<int>(0, r*c)(rng), i, j}); // break ties randomly
		}
	}
	sort(sortedCells.begin(), sortedCells.end());
	reverse(sortedCells.begin(), sortedCells.end());

	for (auto a : sortedCells) {
		int x = a[2];
		int y = a[3];
		allowed[x][y] = 1;
		if (allowed[x-1][y]) uf.merge({x, y}, {x-1, y});
		if (allowed[x+1][y]) uf.merge({x, y}, {x+1, y});
		if (allowed[x][y-1]) uf.merge({x, y}, {x, y-1});
		if (allowed[x][y+1]) uf.merge({x, y}, {x, y+1});

		if (uf.getSize({x, y}) >= n) {
			fprintf(stderr, "min size %d\n", a[0]);
			dfs(x, y);
			break;
		}
		printf("%d\n", uf.getSize({x, y}));
	}

	int score = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (seen[i][j]) {
				score += grid[i][j];
				printf("%d", grid[i][j]);
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	fprintf(stderr, "score %d\n", score);
}