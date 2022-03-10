#include <stdio.h>
#include <stdbool.h>

int N, K;
char allowed[1005][6];
char guess[1005][6];
char result[1005][6];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %s", allowed[i]);
	}
	scanf("%d", &K);
	for (int i = 0; i < N; i++) {
		scanf(" %s", guess[i]);
		scanf(" %s", result[i]);
	}

	for (int i = 0; i < N; i++) {
		bool wrong = false;
		for (int j = 0; j < K; j++) {
			for (int a = 0; a < 5; a++) {
				char expected = '.';
				for (int b = 0; b < 5; b++) {
					if (allowed[i][b] == guess[j][a]) {
						if (a == b) expected = 'G';
						else expected = 'Y';
					}
				}
				if (expected != result[j][a]) wrong = true;
			}
		}
		if (wrong) continue;
		printf("%s\n", allowed[i]);
	}
}