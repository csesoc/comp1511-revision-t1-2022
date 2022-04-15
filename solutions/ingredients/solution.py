N = int(input())
p = list(map(int, input().split()))
canedit = [False for _ in range(N)]
maxsofar = 1
currentsum = 0
for i in reversed(range(N)):
    if p[i] == -1:
        p[i] = maxsofar
        canedit[i] = True
    elif p[i] < maxsofar:
        print("-1 " * N)
        exit()
    maxsofar = p[i]
    currentsum += p[i]
if currentsum > 100:
    print("-1 " * N)
    exit()
i = 0
while i < N and currentsum < 100:
    if not canedit[i] or (i > 0 and p[i] == p[i-1]):
        i += 1
    else:
        p[i] += 1
        currentsum += 1
if currentsum < 100:
    print("-1 " * N)
    exit()
print(" ".join(map(str, p)))