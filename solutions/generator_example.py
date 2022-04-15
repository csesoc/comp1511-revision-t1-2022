import random
import os

# Put a random number here so that test case generation is deterministic
random.seed(YOUR_NUMBER_HERE)

# Use this to output your testcases
def output_case(c, filepath):
    pass

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample1():
    return {
        "N": 8
    }


# Put cases here, CASES should be a list of dicts
CASES = [
    sample1()
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
