#include <cstdio>
#include <queue>
#include <random>
using namespace std;

int R, C, N;
int A[105][105];
bool pushed[105][105];
bool taken[105][105];

int main() {
	scanf("%d %d %d\n", &R, &C, &N);
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			char num;
			scanf(" %c", &num);
			A[r][c] = num - 48;
		}
	}
	for (int r = 1; r <= R; r++) {
		pushed[r][0] = pushed[r][C+1] = true;
	}
	for (int c = 1; c <= C; c++) {
		pushed[0][c] = pushed[R+1][c] = true;
	}

	priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
	pq.push({{A[R/2][C/2], rand()}, {R/2, C/2}});
	pushed[R/2][C/2] = true;
	//fprintf(stderr, "hello\n");
	taken[R/2][C/2] = true;
	//fprintf(stderr, "hello\n");
	for (int n = 1; n < N; n++) {
		//fprintf(stderr, "hello\n");
		int r = pq.top().second.first, c = pq.top().second.second;
		//if (taken[r][c]) fprintf(stderr, "%d %d\n", r, c);
		pq.pop();
		taken[r][c] = true;
		if (!pushed[r+1][c]) {
			pushed[r+1][c] = true;
			pq.push({{A[r+1][c], rand()}, {r+1, c}});
		}
		if (!pushed[r-1][c]) {
			pushed[r-1][c] = true;
			pq.push({{A[r-1][c], rand()}, {r-1, c}});
		}
		if (!pushed[r][c+1]) {
			pushed[r][c+1] = true;
			pq.push({{A[r][c+1], rand()}, {r, c+1}});
		}
		if (!pushed[r][c-1]) {
			pushed[r][c-1] = true;
			pq.push({{A[r][c-1], rand()}, {r, c-1}});
		}
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