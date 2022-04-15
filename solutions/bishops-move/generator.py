import random
import os
import string

# Put a random number here so that test case generation is deterministic
random.seed(69696969)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        for arg in c:
            f.write(str(arg) + "\n")
        

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample1():
    return [
        "a1",
        "h8",
        4,
        "a2",
        "a3",
        "a4",
        "a5"
    ]

def sample2():
    return [
        "a1",
        "h8",
        1,
        "b2"
    ]

def sample3():
    return [
        "d4",
        "g5",
        2,
        "f4",
        "f6"
    ]

# should return 6 ways i think
def sample4():
    return [
        "a1",
        "h8",
        4,
        "c3",
        "e3",
        "c5",
        "f6"
    ]

def sample5():
    return [
        "d4",
        "b6",
        4,
        "c5",
        "e5",
        "d8",
        "c3"
    ]

def sample6():
    return [
        "h1",
        "h7",
        7,
        "h3",
        "f3",
        "d3",
        "c6",
        "e6",
        "g6",
        "c4"
    ]

def random_square(L, R):
    return chr(96 + random.randint(1, 8)) + str(random.randint(1, 8))

def getParity(coord):
    return (coord[0] + coord[1]) % 2

def translateCoord(square):
    x = ord(square[0]) - 97
    y = int(square[1]) - 1
    return (x, y)

def stringifyCoord(coord):
    return chr(97 + coord[0]) + str(1 + coord[1])

def random_case(L, R):
    startingSquare = translateCoord(random_square(L, R))
    endingSquare = translateCoord(random_square(L, R))
    while (getParity(startingSquare) != getParity(endingSquare) or startingSquare == endingSquare):
        endingSquare = translateCoord(random_square(L, R))

    blockingPieces = []
    for _ in range(10):
        currSquare = translateCoord(random_square(L, R))
        while (getParity(startingSquare) != getParity(currSquare) or currSquare == endingSquare 
                or currSquare == startingSquare or stringifyCoord(currSquare) in blockingPieces):
            currSquare = translateCoord(random_square(L, R))
        blockingPieces.append(stringifyCoord(currSquare))

    toReturn = [
        stringifyCoord(startingSquare),
        stringifyCoord(endingSquare),
        10
    ]
    toReturn.extend(blockingPieces)
    return toReturn

# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample1(),
    sample2(),
    sample3(),
    sample4(),
    sample5(),
    sample6(),
    random_case(1, 8),
    random_case(1, 8),
    random_case(1, 8),
    random_case(1, 8)
]

# Generation code. Anything past here should not need to be touched.
def twodigit(x):
    if x < 10:
        return "0" + str(x)
    return str(x)

# Generate the output
inputdir = os.path.join(DIR_PATH, "input")
outputdir = os.path.join(DIR_PATH, "output")

if not os.path.exists(DIR_PATH):
    os.mkdir(DIR_PATH)
if not os.path.exists(inputdir):
    os.mkdir(inputdir)
if not os.path.exists(outputdir):
    os.mkdir(outputdir)

for i, c in enumerate(CASES):
    inputpath = os.path.join(inputdir, "input%s.txt" % (twodigit(i)))
    outputpath = os.path.join(outputdir, "output%s.txt" % (twodigit(i)))

    output_case(c, inputpath)
    os.system(MAKE_OUTPUT_COMMAND.format(inputpath, outputpath))
    
    print("Successfully made testcase at " + inputpath + " and " + outputpath)
