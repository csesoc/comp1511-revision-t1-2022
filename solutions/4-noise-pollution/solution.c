#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXN 110
int n, numsports;
char matches[MAXN][20];
int loudest[MAXN];
char people[MAXN][20];
int loudness[MAXN];
char inp[20];
int main() {
	scanf("%d", &n);
	assert(n <= 100);
	for (int i = 0; i < n; i++) {
		int num;
		scanf(" %s%d%d", people[i], &loudness[i], &num);
		assert(strlen(people[i]) <= 10);
		assert(loudness[i] <= 1000);
		assert(num <= 50);
		for (int j = 0; j < num; j++) {
			scanf(" %s", inp);
			assert(strlen(inp) <= 10);
			int found = 0;
			for (int k = 0; k < numsports; k++) {
				if (!strcmp(matches[k], inp)) {
					found = 1;
					if (loudness[i] >= loudness[loudest[k]]) {
						loudest[k] = i;
					}
				}
			}
			if (!found) {
				strcpy(matches[numsports], inp);
				loudest[numsports] = i;
				numsports++;
			}
		}
	}
	assert(numsports <= 100);
	for (int i = 0; i < numsports; i++) {
		printf("In %s, %s is the loudest!\n", matches[i], people[loudest[i]]);
	}
}
