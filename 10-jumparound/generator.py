import random
import os

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(case, filepath):
    with open(filepath, "w") as f:
        f.write(str(len(case[0])) + "\n")
        f.write(" ".join(str(x) for x in case[0]) + "\n")
        f.write(" ".join(str(pair[0]) for pair in case[1]) + "\n")
        f.write(" ".join(str(pair[1]) for pair in case[1]) + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "./a.out < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

if not os.path.exists("a.out"):
    os.system("g++ solution.cpp -O2 -std=c++11")

def sample1():
    return [4, 1, 3, 1, 2], [(0, 2), (3, 4), (0, 3), (3, 1)]

def sample2():
    return [2, 5, 2, 1], [(0, 1), (1, 2), (2, 3)]

def line(N):
    x = [random.randint(1, 10000) for i in range(N)]
    return x, [(i, i+1) for i in range(N-1)]

def rand(N, a, b):
    edges = []
    for i in range(1, N):
        edges.append((i, random.randint(int(a*(i-1)), int(b*(i-1)))))
    x = [random.randint(1, 10000) for i in range(N)]
    #x = [10000 for i in range(N)]
    perm = list(range(N))
    random.shuffle(perm)
    return [x[perm[i]] for i in range(N)], [(perm[edge[0]], perm[edge[1]]) for edge in edges]

# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample1(),
    sample2(),
    line(100000),
    line(100000),
    rand(100000, 0.0, 1.0),
    rand(100000, 0.8, 1.0),
    rand(100000, 0.0, 0.001),
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
