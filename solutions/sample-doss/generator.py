import random
import os

# Put a random number here so that test case generation is deterministic
random.seed(84302430)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        f.write(" ".join(map(str, c)) + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample1():
    return [
        -1,
        3,
        5,
        -6
    ]

def min_case():
    return [
        -10000,
        10000,
        10000,
        10000
    ]

def max_case():
    return [
        10000,
        -10000,
        10000,
        10000
    ]

def zero_case():
    return [
        0,
        9320,
        8933,
        0
    ]

def random_case(L, R):
    return [
        random.randint(L, R),
        random.randint(L, R),
        random.randint(L, R),
        random.randint(L, R)
    ]

# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample1(),
    min_case(),
    max_case(),
    zero_case(),
    random_case(0, 10000),
    random_case(0, 10000),
    random_case(-10000, 0),
    random_case(-10000, 0),
    random_case(-10000, 10000),
    random_case(-10000, 10000),
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
