// Takes in n and the number of hidden values
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int vals[110];
int main(int argc, char** argv) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int num_hidden = atoi(argv[2]);
	for (int i = 0; i < N; i++) {
		vals[i] = 1;
	}
	
	int amToAdd = max(1, 50/N);

	int sum = N;
	while (sum < 100) {
		int a = min(100-sum, rnd.next(1, amToAdd));

		vals[rnd.next(0, N-1)] += a;

		sum += a;
	}

	assert(accumulate(vals, vals+N, 0) == 100);

	sort(vals, vals+N);
	reverse(vals, vals+N);

	for (int i = 0; i < num_hidden; i++) {
		while (1) {
			int a = rnd.next(0, N-1);
			if (vals[a] > 0) {
				vals[a] = -1;
				break;
			}
		}
	}

	printf("%d\n", N);
	for (int i = 0; i < N; i++) printf("%d ", vals[i]);
	printf("\n");
}