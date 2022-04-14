#include <map>
#include <cstdio>
#include <array>
using namespace std;
#define MAXN 5010
typedef long long ll;
int n;
ll x[MAXN], y[MAXN], ans;
map<array<ll, 3>, int> m; // length squared, 2*midx, 2*midy
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &x[i]);
	for (int i = 0; i < n; i++) scanf("%lld", &y[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			ll len = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			ll midx = x[i]+x[j];
			ll midy = y[i]+y[j];
			ans += m[{len, midx, midy}];
			m[{len, midx, midy}]++;
		}
	}
	printf("%lld\n", ans); 
}

