// Input format: N, num peaks, num swaps, chance of 1, chance of -1, 1 threshold
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define MAX_VAL 1000000
int h[MAXN];
int r[MAXN];
int main(int argc, char** argv) {
	registerGen(argc, argv, 1);
	int n = stoi(argv[1]);
	int num_peaks = stoi(argv[2]);
	int num_swaps = stoi(argv[3]);
	int chance_of_1 = stoi(argv[4]);
	int chance_of_negative_1 = stoi(argv[5]);
	double one_threshold = stod(argv[6]);

	for (int i = 0; i < n; i++) {
		h[i] = rnd.next(1, MAX_VAL);
	}

	vector<int> peaks;
	for (int i = 0; i < num_peaks; i++) {
		peaks.push_back(rnd.next(0, n-1));
	}
	peaks.push_back(0);
	peaks.push_back(n-1);
	sort(peaks.begin(), peaks.end());
	peaks.erase(unique(peaks.begin(), peaks.end()), peaks.end());

	while (peaks.size()%2 == 0) {
		peaks.push_back(rnd.next(0, n-1));
		sort(peaks.begin(), peaks.end());
		peaks.erase(unique(peaks.begin(), peaks.end()), peaks.end());
	}

	for (int i = 1; i < (int)peaks.size()-1; i+=2) {
		sort(h+peaks[i-1], h+peaks[i]+1);
		sort(h+peaks[i], h+peaks[i+1]+1);
		reverse(h+peaks[i], h+peaks[i+1]+1);
	}

	for (int i = 0; i < num_swaps; i++) {
		int index = rnd.next(0, n-2);
		swap(h[index], h[index+1]);
	}

	for (int i = 0; i < n; i++) {
		if (chance_of_negative_1 != 0 && rnd.next(1, chance_of_negative_1) == 1) r[i] = -1;
		if (h[i] >= (1-one_threshold)*MAX_VAL && rnd.next(1, chance_of_1) == 1) r[i] = 1;
	}

	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d%c", h[i], " \n"[i+1==n]);
	for (int i = 0; i < n; i++) printf("%d%c", r[i], " \n"[i+1==n]);
}