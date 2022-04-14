#include <cstdio>
#include <queue>
#include <random>
using namespace std;

int R, C, N;
int A[105][105];
bool taken[105][105];

int depth[105][105], dfslow[105][105], artic[105][105];
void dfs(int r, int c, bool root=false) {
	pair<int, int> adj[4] = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};

	int numchilds = 0;
	dfslow[r][c] = depth[r][c];

	for (int i = 0; i < 4; i++) {
		int r2 = adj[i].first, c2 = adj[i].second;
		if (!taken[r2][c2]) continue;
		
		if (depth[r2][c2] == 0) {
			depth[r2][c2] = depth[r][c] + 1;
			dfs(r2, c2);
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

void find_articulation_nodes() {
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
				dfs(r, c, true);
				roots++;
			}
		}
	}
	assert(roots == 1);
}

int main() {
	FILE* inputfile = fopen("in", "r");
	fscanf(inputfile, "%d %d %d\n", &R, &C, &N);
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			char num;
			fscanf(inputfile, " %c", &num);
			A[r][c] = num - 48;
		}
	}
	stdin = fdopen(0, "r");
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			char num;
			scanf(" %c", &num);
			taken[r][c] = (num != '.');
		}
	}


	for (int r = 1; r <= R; r++) {
		depth[r][0] = depth[r][C+1] = 1e9;
	}
	for (int c = 1; c <= C; c++) {
		depth[0][c] = depth[R+1][c] = 1e9;
	}

	// find_articulation_nodes();

	// for (int r = 1; r <= R; r++) {
	// 	for (int c = 1; c <= C; c++) {
	// 		if (artic[r][c]) {
	// 			printf("A");
	// 		} else if (taken[r][c]) {
	// 			printf("X");
	// 		} else {
	// 			printf(".");
	// 		}
	// 	}
	// 	printf("\n");
	// }

	bool improved = true;
	while (improved) {
		improved = false;
		find_articulation_nodes();
		int worst = 11, worstr, worstc;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				if (!artic[r][c] && taken[r][c] && A[r][c] < worst) {
					worst = A[r][c];
					worstr = r;
					worstc = c;
				}
			}
		}
		int best = -1, bestr, bestc;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				if (!taken[r][c] &&	(	(taken[r+1][c] && (r+1 != worstr || c != worstc))
									 || (taken[r-1][c] && (r-1 != worstr || c != worstc))
									 || (taken[r][c+1] && (r != worstr || c+1 != worstc))
									 || (taken[r][c-1] && (r != worstr || c-1 != worstc))
									) && A[r][c] > best) {
					best = A[r][c];
					bestr = r;
					bestc = c;
				}
			}
		}

		if (best > worst) {
			improved = true;
			taken[bestr][bestc] = true;
			taken[worstr][worstc] = false;
		}
		// printf("%d %d %d\n", worst, worstr, worstc);
		// printf("%d %d %d\n", best, bestr, bestc);
	}

	int ans = 0;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (taken[r][c]) {
				ans += A[r][c];
				printf("%d", A[r][c]);
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	fprintf(stderr, "score: %d\n", ans);
}