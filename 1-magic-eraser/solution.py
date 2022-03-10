X = int(input())
Y = int(input())

assert 2 <= X <= 500
assert 1 <= Y < X
assert X % Y == 0

cube_area = (Y ** 2) * 6
n_cubes = (X // Y) ** 3
print(cube_area * n_cubes)

