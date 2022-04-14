import random
import os

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        f.write(str(len(c)) + "\n")
        f.write(" ".join(str(p[0]) for p in c) + "\n")
        f.write(" ".join(str(p[1]) for p in c) + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here

def sample1():
    return [(0, 4), (5, 4), (2, 5), (1, 2), (4, 6), (4, 1)]

pairs = {}
for i in range(1001):
    #print(i)
    for j in range(1001):
        if i**2+j**2 in pairs:
            pairs[i**2+j**2].append((i, j))
        else:
            pairs[i**2+j**2] = [(i, j)]
goods = [p for p in pairs if len(pairs[p]) > 5]

def rand(N, K):
    points = set()
    while len(points) < N:
        centerx = random.randint(2000, 18000)
        centery = random.randint(2000, 18000)
        dist = random.choice(goods)
        num = random.randint(1, K)
        while num > 0:
            dx, dy = random.choice(pairs[dist])
            if random.randint(0, 1):
                dx, dy = dy, dx
            if random.randint(0, 1):
                dx *= -1

            if (centerx + dx) % 2 == 0 and (centery + dy) % 2 == 0:
                if random.randint(0, 5):
                    points.add( ((centerx + dx)//2, (centery + dy)//2) )
                if random.randint(0, 5):
                    points.add( ((centerx - dx)//2, (centery - dy)//2) )

            num -= 1

    pointslist = list(points)[:N]
    random.shuffle(pointslist)
    return pointslist

# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample1(),
    rand(50, 10),
    rand(1000, 10),
    rand(1000, 50),
    rand(1000, 300),
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
