#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <random>
#include <set>
#include <queue>
#include <assert.h>
using namespace std;

random_device rd;
mt19937_64 rng(rd());
uniform_int_distribution<short> choice(1, 20);
uniform_int_distribution<short> index_dis(0, 9999);
uniform_real_distribution<double> real_dis(0, 1);

constexpr short R = 100, C = 100, N = 1000;
constexpr pair<short, short> DIRS[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

short A[10005];

struct State {
	bool taken[10005];
	short numTaken = 0, score = 0;

	void readFromInput() {
		ifstream fin{ "best.out" };
		for (short i = 0; i < R * C; ++i) {
			char val;
			fin >> val;
			assert(val != '\n');
			if (val == '#') {
				taken[i] = true;
				numTaken++;
				score += A[i];
			}
		}
		fin.close();
	}

	void writeToOutput() {
		ofstream fout{ "best.out" };
		for (short r = 0; r < R; r++) {
			for (short c = 0; c < C; c++) {
				fout << (taken[r * 100 + c] ? '#' : '.');
			}
			fout << '\n';
		}
		fout.close();
	}

	void print() {
		for (short r = 0; r < R; r++) {
			for (short c = 0; c < C; c++) {
				if (taken[r * 100 + c]) cout << A[r * 100 + c];
				else cout << '.';
			}
			cout << '\n';
		}
	}

	bool isSingleComponent() {
		if (numTaken == 0) return true;
		auto start = find(begin(taken), end(taken), true) - begin(taken);
		
		short size = 0;
		bool seen[10005];
		fill(begin(seen), end(seen), false);

		queue<short> q;
		seen[start] = true;
		q.push(start);
		++size;

		while (!q.empty()) {
			short curr = q.front();
			q.pop();
			
			for (auto dir : DIRS) {
				short nR = (curr / 100) + dir.first;
				short nC = (curr % 100) + dir.second;
				if (0 <= min(nR, nC) && max(nR, nC) < R && taken[nR * 100 + nC] && !seen[nR * 100 + nC]) {
					seen[nR * 100 + nC] = true;
					q.push(nR * 100 + nC);
					++size;
				}
			}
		}
		return size == numTaken;
	}

	State mutate() {
		while (true) {
			State output = *this;
			short i = index_dis(rng);
			if (taken[i]) {
				output.taken[i] = false;
				output.score -= A[i];
				output.numTaken--;
			}
			else if (numTaken < N) {
				output.taken[i] = true;
				output.score += A[i];
				output.numTaken++;
			}
			else continue;

			if (output.isSingleComponent()) return output;
		}
	}
};

bool acceptance(short delta, double T) {
	if (delta >= 0) return true;
	return real_dis(rng) <= exp(delta / T);
}

void simulate() {
	State start;
	if (true) {
		start.readFromInput();
	}
	else {
		start.taken[0] = true;
		start.score += A[0];
		start.numTaken++;
	}
	start.print();
	cout << start.numTaken;
	assert(start.isSingleComponent() && "Not single component");

	short bestScore = start.score;

	double T = 1e-1;
	while (T > 1e-4) {
		T *= 0.99999;

		State curr = start.mutate().mutate();
		//cout << curr.score << "\n";

		if (acceptance(curr.score - start.score, T)) {
			start = curr;

			if (curr.score > bestScore) {
				cout << "!!!!!!!! " << curr.score << "\n";
				bestScore = curr.score;
				curr.writeToOutput();
			}
		}
	}
}

signed main() {
	//cin.tie(0); ios::sync_with_stdio(0);
	ifstream cin{ "../input.txt" };
	short _;
	cin >> _ >> _ >> _;
	for (short i = 0; i < R * C; i++) {
		char num;
		cin >> num;
		A[i] = num - '0';
	}

	simulate();
}