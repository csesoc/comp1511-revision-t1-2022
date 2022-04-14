// Start all values >= threshold, and at each point add the largest adjacent value (akin to prim's algorithm, but with multiple sources)
// Once we have a big enough connected component, dfs to find a component of exactly size n
#include "articulation.h"
#include <bits/stdc++.h>
using namespace std;
#define MAXN 110
#define THRESHOLD 8
int grid[MAXN][MAXN], r, c, n;
int allowed[MAXN][MAXN], seen[MAXN][MAXN];
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

priority_queue<array<int, 4 >> pq;

int numSeen;
void dfs(int x, int y, int mxvisited) {
	if (numSeen == mxvisited) return;
	if (seen[x][y]) return;
	seen[x][y] = 1;
	numSeen++;
	if (allowed[x-1][y]) dfs(x-1, y, mxvisited);
	if (allowed[x+1][y]) dfs(x+1, y, mxvisited);
	if (allowed[x][y-1]) dfs(x, y-1, mxvisited);
	if (allowed[x][y+1]) dfs(x, y+1, mxvisited);
}


void add(int x, int y, mt19937 &rng) {
	allowed[x][y] = true;

	if (allowed[x-1][y]) uf.merge({x, y}, {x-1, y});
	else pq.push({grid[x-1][y], uniform_int_distribution<int>(0, r*c)(rng), x-1, y});
	if (allowed[x+1][y]) uf.merge({x, y}, {x+1, y});
	else pq.push({grid[x+1][y], uniform_int_distribution<int>(0, r*c)(rng), x+1, y});
	if (allowed[x][y-1]) uf.merge({x, y}, {x, y-1});
	else pq.push({grid[x][y-1], uniform_int_distribution<int>(0, r*c)(rng), x, y-1});
	if (allowed[x][y+1]) uf.merge({x, y}, {x, y+1});
	else pq.push({grid[x][y+1], uniform_int_distribution<int>(0, r*c)(rng), x, y+1});

	if (uf.getSize({x, y}) >= n) {
		pair<int, int> startPoint = { x, y };
		while (1) {
			fill_n(seen[0], MAXN*MAXN, 0);
			numSeen = 0;
			dfs(startPoint.first, startPoint.second, 1e9);
			if (numSeen == n) {
				break;
			}
			assert(numSeen > n);
			find_articulation_nodes(seen, r, c);
			array<int, 3> mn_nonart = { 10, 0, 0 };
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					if (seen[i][j] && !is_articulation_point(i, j)) {
						mn_nonart = min(mn_nonart, { grid[i][j], i, j });
					}
				}
			}
			if (mn_nonart[0] >= THRESHOLD) break;
			allowed[mn_nonart[1]][mn_nonart[2]] = false;
			if (!allowed[startPoint.first][startPoint.second]) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						if (seen[i][j] && allowed[i][j]) startPoint = { i, j };
					}
				}
			}
		}

		fill_n(seen[0], MAXN*MAXN, 0);
		numSeen = 0;
		dfs(startPoint.first, startPoint.second, n);
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
		fprintf(stderr, "%d  ", score);
		exit(0);
	}
}

int main(int argc, char** argv) {
	int seed;
	if (argc == 2) {
		seed = stoi(argv[1]);
	} else {
		seed = chrono::steady_clock::now().time_since_epoch().count();
	}
	mt19937 rng(seed);
	fprintf(stderr, "%d: ", seed);

	scanf("%d%d%d", &r, &c, &n);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			scanf(" %c", &c);
			grid[i][j] = c - '0';

			if (grid[i][j] >= THRESHOLD) {
				add(i, j, rng);
			}
		}
	}

	while (pq.size()) {
		auto a = pq.top();
		pq.pop();
		int x = a[2], y = a[3];
		if (allowed[x][y]) continue;
		add(x, y, rng);
	}

}