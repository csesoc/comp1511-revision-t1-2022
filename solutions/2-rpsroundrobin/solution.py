N = int(input())
s = input()

score = 0
for i in range(N):
    if i % 3 == 0: other = "R"
    if i % 3 == 1: other = "P"
    if i % 3 == 2: other = "S"

    won = False
    ours = s[i]

    if other == "R" and ours == "P": won = True
    if other == "P" and ours == "S": won = True
    if other == "S" and ours == "R": won = True

    if won:
        # Rounds are 1-indexed.
        score += i + 1

print(score)

