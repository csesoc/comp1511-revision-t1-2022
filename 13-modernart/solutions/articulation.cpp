#include "articulation.h"
#include <bits/stdc++.h>
using namespace std;
int depth[105][105], dfslow[105][105], artic[105][105];
void dfs(int taken[110][110], int r, int c, bool root=false) {
	pair<int, int> adj[4] = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};

	int numchilds = 0;
	dfslow[r][c] = depth[r][c];

	for (int i = 0; i < 4; i++) {
		int r2 = adj[i].first, c2 = adj[i].second;
		if (!taken[r2][c2]) continue;
		
		if (depth[r2][c2] == 0) {
			depth[r2][c2] = depth[r][c] + 1;
			dfs(taken, r2, c2);
			dfslow[r][c] = min(dfslow[r][c], dfslow[r2][c2]);
			if (dfslow[r2][c2] >= depth[r][c] && !root) {
				artic[r][c] = true;
			}
			numchilds++;
		} else {
			dfslow[r][c] = min(dfslow[r][c], depth[r2][c2]);
		}
	}

	if (root && numchilds > 1) {
		artic[r][c] = true;
	}
}

void find_articulation_nodes(int taken[110][110], int R, int C) {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			depth[r][c] = 0;
			dfslow[r][c] = 0;
			artic[r][c] = false;
		}
	}
	int roots = 0;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (taken[r][c] && depth[r][c] == 0) {
				depth[r][c] = 1;
				dfs(taken, r, c, true);
				roots++;
			}
		}
	}
	assert(roots == 1);
}

bool is_articulation_point(int x, int y) {
	return artic[x][y];
}