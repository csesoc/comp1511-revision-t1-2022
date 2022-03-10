import sys
sys.setrecursionlimit(10**9)
N = int(input())
x = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x[0] -= 1
adj = [[] for i in range(N)]
ans = 2*N - 1
for i in range(N-1):
	adj[a[i]].append(b[i])
	adj[b[i]].append(a[i])
	x[a[i]] -= 1
	x[b[i]] -= 1
def dfs(u, prev):
	global ans
	for v in adj[u]:
		if v != prev:
			dfs(v, u)
			if x[v] > 0:
				ans += x[v] * 2
				x[u] -= x[v]
dfs(0, -1)
if x[0] > 0:
	ans += x[0] * 2
print(ans)