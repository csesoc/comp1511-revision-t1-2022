#include <bits/stdc++.h>
using namespace std;

int n, m, tx, ty, min1 = 1e9, max1 = -1e9, min2 = 1e9, max2 = -1e9; 

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tx);
        min1 = min(min1, tx);
        max1 = max(max1, tx);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ty);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &tx);
        min2 = min(min2, tx);
        max2 = max(max2, tx);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ty);
    }

    if (max(min1, min2) <= min(max1, max2)) {
        printf("Collision!\n");
    } else {
        printf("No Collision!\n");
    }
}
