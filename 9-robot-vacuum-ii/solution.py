def genPrefix(arr, target):
    prefixSum = [0]
    for val in arr:
        prefixSum.append(prefixSum[-1] + (val == target))
    return prefixSum

def rangeSum(prefixSum, l, r):
    return prefixSum[r + 1] - prefixSum[l]

N = int(input())
S = input()
lPrefix = genPrefix(S, "L")
rPrefix = genPrefix(S, "R")
uPrefix = genPrefix(S, "U")
dPrefix = genPrefix(S, "D")

xDist = 0
yDist = 0
for i in range(len(S)):
    xDist = max(xDist, min(
        rangeSum(lPrefix, 0, i) + rangeSum(rPrefix, i + 1, len(S) - 1),
        rangeSum(rPrefix, 0, i) + rangeSum(lPrefix, i + 1, len(S) - 1)
    ))
    yDist = max(yDist, min(
        rangeSum(uPrefix, 0, i) + rangeSum(dPrefix, i + 1, len(S) - 1),
        rangeSum(dPrefix, 0, i) + rangeSum(uPrefix, i + 1, len(S) - 1)
    ))

print(xDist + yDist)
