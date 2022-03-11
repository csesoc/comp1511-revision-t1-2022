N = int(input())
S = input()

xDist = 0
yDist = 0
for i in range(len(S)):
    xDist = max(xDist, min(
        S[:i].count("L") + S[i:].count("R"),
        S[:i].count("R") + S[i:].count("L")
    ))
    yDist = max(yDist, min(
        S[:i].count("U") + S[i:].count("D"),
        S[:i].count("D") + S[i:].count("U")
    ))

print(xDist + yDist)
