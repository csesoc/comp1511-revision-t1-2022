import random
import os
import string

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        f.write(str(len(c)) + "\n" + "".join(map(str, c)) + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "python solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample0():
    return "URDURDUDL"

def gen(N, choices = "UDLR"):
    return "".join(random.choice(choices) for i in range(N))
        
# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample0(),
    gen(10),
    gen(100),
    gen(1000),
    gen(100000),
    gen(100000, "UUUUUUDDDDDDLR"),
    gen(100000, "UUUUUUUUUUUDLR"),
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
