def get_result(ans, guess):
	res = ""
	for i in range(5):
		if ans[i] == guess[i]:
			res += 'G'
		elif guess[i] in ans:
			res += 'Y'
		else:
			res += '.'
	return res

N = int(input())
candidates = []
for i in range(N):
	candidates.append(input().strip())

K = int(input())
for i in range(K):
	guess = input().strip()
	res = input().strip()
	new_cands = []
	for cand in candidates:
		if get_result(cand, guess) == res:
			new_cands.append(cand)
	candidates = new_cands

for c in candidates:
	print(c)