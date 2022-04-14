import random
import os

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        f.write(str(len(c)) + "\n" + c + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

vowels = 'AEIOU'
consonants = 'BCDFGHJKLMNPQRSTVWXYZ'

# Put functions here

def sample1():
    return 'MORECONSONANTS'

def sample2():
    return 'UWU'

def cv(c, v):
    word = [random.choice(consonants) for _ in range(c)] + [random.choice(vowels) for _ in range(v)]
    random.shuffle(word)
    return "".join(word)

# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample1(),
    sample2(),
    cv(60000, 40000),
    cv(50000, 50000),
    cv(40000, 60000),
    cv(49999, 50000),
    cv(50000, 49999),
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
