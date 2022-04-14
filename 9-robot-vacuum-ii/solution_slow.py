# Ryan
N = int(input())
S = input()

dist = 0
for i in range(len(S)):
    xDist = max(
        min(S[:i].count("L"), S[i:].count("R")),
        min(S[:i].count("R"), S[i:].count("L"))
    )
    yDist = max(
        min(S[:i].count("U"), S[i:].count("D")),
        min(S[:i].count("D"), S[i:].count("U"))
    )
    dist = max(dist, xDist + yDist)

print(dist)
