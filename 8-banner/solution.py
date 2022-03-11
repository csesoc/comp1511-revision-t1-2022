N = int(input())
S = list(input().strip())
ans = 0

for i in range(N):
	if S[i]=='_':
		if i > 1 and S[i-2]=='I' and S[i-1]=='M':
			S[i] = 'C'
		elif i < N-1 and S[i+1]=='M':
			S[i] = 'I'
		elif i > 0 and S[i-1]=='I':
			S[i] = 'M'
		else:
			S[i] = 'I'
	if i > 1 and S[i-2]=='I' and S[i-1]=='M' and S[i]=='C':
		ans += 1

print(ans)