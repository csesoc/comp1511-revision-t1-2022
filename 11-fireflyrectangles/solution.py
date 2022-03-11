N = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

thing = {}
ans = 0
for i in range(N):
	for j in range(i, N):
		stuff = x[i]+x[j], y[i]+y[j], (x[i]-x[j])**2 + (y[i]-y[j])**2
		if stuff in thing:
			ans += thing[stuff]
		else:
			thing[stuff] = 1

print(ans)