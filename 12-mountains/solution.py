def find_dis(n, h, r):
	cum_h = [0]

	for i in range(1, n):
		cum_h.append(cum_h[-1]+(h[i]-h[i-1])**2)

	cum_r = [r[0]]
	for x in r[1:]:
		cum_r.append(cum_r[-1]+x)

	last = [-1]*(2*n)

	dis_left = [int(1e18)]
	for i in range(1, n):
		ind = last[cum_r[i-1]-1]
		if ind == -1:
			dis_left.append(int(1e18))
		else:
			# Walk until ind+1
			dis = cum_h[i-1] - cum_h[ind+1]
			dis_left.append(dis)
		last[cum_r[i-1]] = i-1

	return dis_left


n = int(input())
h = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]

n += 2
h = [int(1e9)] + h + [int(1e9)]
r = [0] + r + [0]

dis_left = find_dis(n, h, r)

h.reverse()
r.reverse()

dis_right = find_dis(n, h, r)

dis_right.reverse()
h.reverse()
r.reverse()

ans = (int)(1e18)

for i in range(1, n-1):
	if r[i] == 1:
		ans = min(ans, 2*h[i]**2)
	elif r[i] == -1:
		# Case: walk left and right until positive
		dis = dis_left[i]+dis_right[i] + h[i]**2 + (h[i]-h[i-1])**2 + (h[i]-h[i+1])**2
		ans = min(ans, 2*dis)
		# Case: walk left until positive
		dis = dis_left[i+1] + h[i]**2
		ans = min(ans, 2*dis)
		# Case: walk right until positive
		dis = dis_right[i-1] + h[i]**2
		ans = min(ans, 2*dis)
	else:
		# Case: walk left until positive
		dis = dis_left[i+1] + h[i]**2
		ans = min(ans, 2*dis)
		# Case: walk right until positive
		dis = dis_right[i-1] + h[i]**2
		ans = min(ans, 2*dis)

print(ans)