#include <bits/stdc++.h>
using namespace std;

int n, ans;
char jack, opp;

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf(" %c", &jack);
        
        if (i % 3 == 0) {
            opp = 'S';
        } else if (i % 3 == 1) {
            opp = 'R';
        } else if (i % 3 == 2) {
            opp = 'P';
        }

        ans += ((jack == 'R' && opp == 'S') || (jack == 'P' && opp == 'R') || (jack == 'S' && opp == 'P')) * i;
    }

    printf("%d\n", ans);
}