import random
import os
import string

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(c, filepath):
    with open(filepath, "w") as f:
        f.write(str(len(c)) + "\n" + "\n".join(map(str, c)) + "\n")

# Make output command
MAKE_OUTPUT_COMMAND = "python3 solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample0():
    return [
        "pat    1000 2 nrl boxing",
        "angus  20   2 soccer nrl",
        "isaiah 0    2 tennis cricket",
        "zhi    1    0",
        "ryan   50   1 tennis",
    ]

def genStrings(N):
    names = set()
    while len(names) < N:
        curr = "".join(random.choice(string.ascii_lowercase) for rep in range(10))
        names.add(curr)
    return list(names)

def big(N, numSports, maxSports):
    assert N * numSports <= 100000
    assert maxSports <= numSports
    
    names = genStrings(N)
    sports = genStrings(numSports)
    output = []
    for loudness, name in enumerate(names):
        currSports = random.sample(sports, random.randrange(0, maxSports))
        output.append(" ".join([name, str(loudness), str(len(currSports)), *currSports]))
    random.shuffle(output)
    return output
        
# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    sample0(),
    big(50, 10, 10),
    big(50, 50, 10),
    big(100, 100, 20),
    big(100, 100, 50)
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
