import random
import os
import string
from shapely.ops import unary_union, cascaded_union
from shapely.geometry import Polygon

# Put a random number here so that test case generation is deterministic
random.seed(563426471)

# Use this to output your testcases
def output_case(i, filepath):
    coordsN, coordsM = i
    with open(filepath, "w") as f:
        print(len(coordsN), len(coordsM), file=f)
        for val in coordsN: print(*val, file=f)
        for val in coordsM: print(*val, file=f)
        
    # visualise using desmos
    print()
    print("polygon(" + ",".join(map(str, coordsN)) + ")")
    print("polygon(" + ",".join(map(str, coordsM)) + ")")
    

# Make output command
MAKE_OUTPUT_COMMAND = "python solution.py < {0} > {1}"
# Dir that stores all the test cases
DIR_PATH = "tests"

# Put functions here
def sample0():
    return None

def genRect(MAX_RANGE):
    x1 = random.randint(-MAX_RANGE, MAX_RANGE)
    y1 = random.randint(-MAX_RANGE, MAX_RANGE)
    x2 = random.randint(-MAX_RANGE, MAX_RANGE)
    y2 = random.randint(-MAX_RANGE, MAX_RANGE)
    x1, x2 = min(x1, x2), max(x1, x2)
    y1, y2 = min(y1, y2), max(y1, y2)
    return x1, y1, x2, y2

def intersect(x1, y1, x2, y2, x1_, y1_, x2_, y2_):
    #intesection area > 0, aka mindbending scenario
    x = max(x1, x1_) - min(x2, x2_)
    y = max(y1, y1_) - min(y2, y2_)

    if x1 > x2_ or x1_ > x2 or y1 > y2_ or y1_ > y2:
        overlap = 0
    else:
        overlap = abs(x * y)
    
    return overlap > 0

def inside(x, y, x1_, y1_, x2_, y2_):
    return x1_ < x < x2_ and y1_ < y < y2_

def union(rects):
    """corners = []
    for i, rectI in enumerate(rects):
        for x in [0, 2]:
            for y in [1, 3]:
                if not any(inside(rectI[x], rectI[y], *rectJ) and i != j for j, rectJ in enumerate(rects)):
                    corners.append((rectI[x], rectI[y]))"""
    rects = [Polygon([(i[0], i[1]), (i[0], i[3]), (i[2], i[3]), (i[2], i[1])]) for i in rects]
    assert all(i.is_valid for i in rects)
    
    output = unary_union(rects)
    output = [(int(i[0]), int(i[1])) for i in list(output.exterior.coords)]
    return output
    
def gen(N, M, MAX_RANGE = 1_000_000_000, SPLIT = None):
    #why is generating data harder than the problem itself lol
    #generate random polygons and find intersections
    rectsN, rectsM = [], []
    while len(rectsN) < N:
        x1, y1, x2, y2 = genRect(MAX_RANGE//2)
        if SPLIT == None or x2 < SPLIT:
            if rectsN == [] or any(intersect(x1, y1, x2, y2, *i) for i in rectsN):
                rectsN.append((x1, y1, x2, y2))
    

    while len(rectsM) < M:
        x1, y1, x2, y2 = genRect(MAX_RANGE)
        if SPLIT == None or x1 >= SPLIT:
            if (rectsM == [] or any(intersect(x1, y1, x2, y2, *i) for i in rectsM)) and not any(intersect(x1, y1, x2, y2, *i) for i in rectsN):
                rectsM.append((x1, y1, x2, y2))
    #[print("f"+str(i)) for i in rectsN]
    #print()
    #[print("f"+str(i)) for i in rectsM]

    return union(rectsN), union(rectsM)
    
# Put cases here, CASES should be a list of dicts
# but its a list of lists here so cop it
CASES = [
    gen(10, 10, 1_000),
    gen(10, 10, 1_000, SPLIT=69),
    gen(100, 100, 1_000_000),
    gen(100, 100, 1_000_000, SPLIT=-210),
    gen(1000, 1000, 1_000_000_000),
    gen(1000, 1000, 1_000_000_000, SPLIT=531),
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
