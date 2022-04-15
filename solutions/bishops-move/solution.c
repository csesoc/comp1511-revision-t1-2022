#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char xs, ys, xe, ye;
int N, dist[200][200];
bool blocked[200][200];

void min(int *a, int b) {
    if (*a > b) *a = b;
}

int numpaths = 0;
char ans1[100][100], ans2[100][100];

bool less(int a, int b) {
    for (int i = 0; i <= dist[xs][ys]; i++) {
        if (ans1[a][i] < ans1[b][i]) return true;
        if (ans1[a][i] > ans1[b][i]) return false;
        if (ans2[a][i] < ans2[b][i]) return true;
        if (ans2[a][i] > ans2[b][i]) return false;
    }
    return false;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char path1[100], path2[100];
void findpaths(char r, char c) {
    path1[dist[r][c]] = r;
    path2[dist[r][c]] = c;
    if (dist[r][c] == 0) {
        for (int i = 0; i <= dist[xs][ys]; i++) {
            ans1[numpaths][i] = path1[dist[xs][ys] - i];
            ans2[numpaths][i] = path2[dist[xs][ys] - i];
        }
        numpaths++;
    }
    for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx++, dy++) {
        if (dist[r+dx][c+dy] == dist[r][c] - 1) findpaths(r+dx, c+dy);
    }
    for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx++, dy--) {
        if (dist[r+dx][c+dy] == dist[r][c] - 1) findpaths(r+dx, c+dy);
    }
    for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx--, dy++) {
        if (dist[r+dx][c+dy] == dist[r][c] - 1) findpaths(r+dx, c+dy);
    }
    for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx--, dy--) {
        if (dist[r+dx][c+dy] == dist[r][c] - 1) findpaths(r+dx, c+dy);
    }
}

int main() {
    scanf(" %c%c", &xs, &ys);
    scanf(" %c%c", &xe, &ye);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char x, y;
        scanf(" %c%c", &x, &y);
        blocked[x][y] = true;
    }
    for (int i = 'a'-1; i <= 'h'+1; i++) {
        blocked[i]['1'-1] = true;
        blocked[i]['8'+1] = true;
    }
    for (int i = '1'-1; i <= '8'+1; i++) {
        blocked['a'-1][i] = true;
        blocked['h'+1][i] = true;
    }

    for (int r = 'a'; r <= 'h'; r++) {
        for (int c = '1'; c <= '8'; c++) {
            dist[r][c] = 1e9;
        }
    }
    dist[xe][ye] = 0;

    for (int i = 0; i < 64; i++) {
        for (int r = 'a'; r <= 'h'; r++) {
            for (int c = '1'; c <= '8'; c++) {
                for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx++, dy++) {
                    min(&dist[r+dx][c+dy], dist[r][c] + 1);
                }
                for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx++, dy--) {
                    min(&dist[r+dx][c+dy], dist[r][c] + 1);
                }
                for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx--, dy++) {
                    min(&dist[r+dx][c+dy], dist[r][c] + 1);
                }
                for (int dx = 0, dy = 0; !blocked[r+dx][c+dy]; dx--, dy--) {
                    min(&dist[r+dx][c+dy], dist[r][c] + 1);
                }
            }
        }
    }

    if (dist[xs][ys] < 1e9) {
        findpaths(xs, ys);
        for (int a = 0; a < numpaths; a++) {
            for (int b = a+1; b < numpaths; b++) {
                if (less(b, a)) {
                    for (int i = 0; i <= dist[xs][ys]; i++) {
                        swap(&ans1[a][i], &ans1[b][i]);
                        swap(&ans2[a][i], &ans2[b][i]);
                    }
                }
            }
            for (int i = 0; i <= dist[xs][ys]; i++) {
                printf("%c%c ", ans1[a][i], ans2[a][i]);
            }
            printf("\n");
        }
    } else {
        printf("No possible path\n");
    }
}