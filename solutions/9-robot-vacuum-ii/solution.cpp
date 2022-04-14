// Ryan
#include <iostream>
#include <algorithm>
using namespace std;

int N, prefix[4][100005];
string S;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		prefix[0][i+1] = prefix[0][i] + (S[i] == 'U');
		prefix[1][i+1] = prefix[1][i] + (S[i] == 'D');
		prefix[2][i+1] = prefix[2][i] + (S[i] == 'L');
		prefix[3][i+1] = prefix[3][i] + (S[i] == 'R');
	}

	int dist = 0;
	for (int i = 0; i < N; ++i) {
		int xDist = max(
			min(prefix[2][i + 1], prefix[3][N] - prefix[3][i + 1]),
			min(prefix[3][i + 1], prefix[2][N] - prefix[2][i + 1])
		);
		int yDist = max(
			min(prefix[0][i + 1], prefix[1][N] - prefix[1][i + 1]),
			min(prefix[1][i + 1], prefix[0][N] - prefix[0][i + 1])
		);
		dist = max(dist, xDist + yDist);
	}

	cout << dist << "\n";
}