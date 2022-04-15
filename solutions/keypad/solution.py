n = int(input())

grid = [ ["1", "2", "3"], ["4", "5", "6"], ["7", "8", "9"] ]

x = 0
y = 0
ans = ""

moves = input().strip()

for i in moves:
    if (i == 'L'):
        x -= 1
    elif (i == 'R'):
        x += 1
    elif (i == 'U'):
        y -= 1
    elif (i == 'D'):
        y += 1
    elif (i == 'P'):
        ans += grid[y][x]
    else:
        assert False

print(ans)


