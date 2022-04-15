# Translates a square like a4 into (0, 3)
def translateCoord(square):
    x = ord(square[0]) - 97
    y = int(square[1]) - 1
    return (x, y)

def stringifyCoord(coord):
    return chr(97 + coord[0]) + str(1 + coord[1])

def getParity(coord):
    return (coord[0] + coord[1]) % 2

def findNeighbours(grid, coord, bp):
    neighbours = []
    i = coord[0]
    j = coord[1]
    while i < 7 and j < 7:
        i += 1
        j += 1
        if (i, j) in bp:
            break
        neighbours.append((i, j))

    i = coord[0]
    j = coord[1]
    while i > 0 and j < 7:
        i -= 1
        j += 1
        if (i, j) in bp:
            break
        neighbours.append((i, j))

    i = coord[0]
    j = coord[1]
    while i > 0 and j > 0:
        i -= 1
        j -= 1
        if (i, j) in bp:
            break
        neighbours.append((i, j))

    i = coord[0]
    j = coord[1]
    while i < 7 and j > 0:
        i += 1
        j -= 1
        if (i, j) in bp:
            break
        neighbours.append((i, j))

    return neighbours

# Sample input

# a1
# h8
# 4
# a2
# a3
# a4
# a5

# argList = open("input01.txt").read().split('\n')

startingSquare = translateCoord(input())
endingSquare = translateCoord(input())
numBlockingPieces = int(input())
blockingPieces = []
for _ in range(numBlockingPieces):
    blockingPieces.append(translateCoord(input()))

# Deal with the trivial case
if getParity(startingSquare) != getParity(endingSquare):
    print("No possible path")
    exit(0)

grid = [[0 for x in range(8)] for y in range(8)]

# Non-trivial case, there could be a path
queue = [(startingSquare, 1)]
visited = {}
visited[startingSquare] = 1
foundR = 99999
while queue:
    coord, r = queue.pop(0)

    if coord == endingSquare:
        foundR = r
    elif r > foundR:
        break

    for neighbour in findNeighbours(grid, coord, blockingPieces):
        if visited.get(neighbour, -1) == -1:
            visited[neighbour] = r + 1
            queue.append((neighbour, r + 1))


def produceList(thisSquare, startingSquare):
    if thisSquare == startingSquare:
        return [stringifyCoord(startingSquare)]

    resultList = []
    for neighbour in findNeighbours(grid, thisSquare, blockingPieces):
        # print(visited.get(neighbour, -99999), visited.get(thisSquare) - 1)
        if visited.get(neighbour, -99999) == visited.get(thisSquare) - 1:
            resultList.extend(produceList(neighbour, startingSquare))
    return [stringifyCoord(thisSquare) + " " + result for result in resultList]


if foundR == 99999:
    print("No possible path")
else: 
    # print("Round ended at " + str(1 + visited.get(endingSquare)))
    resultList = produceList(endingSquare, startingSquare)
    paths = []
    for result in resultList:
        path = result.split(' ')
        path.reverse()
        paths.append(' '.join(path))
    paths.sort()
    print(*paths, sep='\n')