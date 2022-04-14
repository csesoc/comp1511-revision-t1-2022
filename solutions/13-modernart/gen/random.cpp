#include "testlib.h"
#include <cstdio>

int main(int argc, char **argv) {
	assert(argc == 4);
	int R = atoi(argv[1]);
	int C = atoi(argv[2]);
	int N = atoi(argv[3]);
	printf("%d %d %d\n", R, C, N);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d", rnd.next(0, 9));
		}
		printf("\n");
	}
}