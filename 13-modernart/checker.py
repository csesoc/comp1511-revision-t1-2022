
# Start of HEAD
import json
import string
import sys
# End of HEAD
        

# Start of BODY
'''
TestStruct::
testcase_id                   [int] ID of the test-case
testcase_input_path           [str] File path to test-case input
testcase_output_path          [str] File path to test-case output generated by the problem solver
testcase_expected_output_path [str] File path to test-case expected output to be matched with
testcase_error_path           [str] File path to test-case STDERR
metadata_file_paths           [list<str>] File paths to Question metadata (Extra files usually used for defining traning sets)
submission_code_path          [str] File path to submission source code
submission_language           [str] Language token of submission
testcase_result               [bool] Set to True if test-case output matches test-case expected output. Matching is done line by line
testcase_signal               [int] Exit code of the test-case process
testcase_time                 [float] Time taken by the test-case process in seconds
testcase_memory               [int] Peak memory of the test-case process determined in bytes
data                          [str] <Future use>
ResultStruct::
result      [bool]  Assign test-case result. True determines success. False determines failure
score       [float] Assign test-case score. Normalized between 0 to 1
message     [str] Assign test-case message. This message is visible to the problem solver
'''


def run_custom_checker(t_obj, r_obj):
    # Don't print anything to STDOUT in this function
    # Enter your custom checker scoring logic here
    
    input_file = t_obj.testcase_input_path
    output_file = t_obj.submission_code_path
    
    with open(input_file, "r") as f:
        R, C, N = map(int, f.readline().split())
        A = [list(map(int, f.readline().strip())) for r in range(R)]

    with open(output_file, "r") as f:
        taken = f.read().split()
        # Allows any whitespace to separate rows not just newlines, but who cares

    r_obj.result = False
    r_obj.score = 0.0
    r_obj.message = "Invalid painting"
    if len(taken) != R:
        return
    if not all(len(row) == C for row in taken):
        return
    if not all(all(cell in ".#" for cell in row) for row in taken):
        return
    if not sum(sum(cell == '#' for cell in row) for row in taken) == N:
        return

    seen = [[False for c in range(C)] for r in range(R)]
    def dfs(r, c):
        if r < 0 or r >= R or c < 0 or c >= C or seen[r][c] or not taken[r][c] == '#':
            return
        seen[r][c] = True
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)
    roots = 0
    for r in range(R):
        for c in range(C):
            if not seen[r][c] and taken[r][c] == '#':
                roots += 1
                dfs(r, c)
    if roots != 1:
        return
    
    S = 0
    for r in range(R):
        for c in range(C):
            if taken[r][c] == '#':
                S += A[r][c]

    from math import exp
    score = round(min(1, exp(0.0015 * (S - 7500))), 4)

    # if score == 1.0:
    #     r_obj.result = True
    #     r_obj.score = 1.0
    #     r_obj.message = "Success: S=" + str(S)
    # elif score == 0.0:
    #     r_obj.result = False
    #     r_obj.score = 0.0
    #     r_obj.message = "Wrong Answer: S=" + str(S)
    # else:
    #     r_obj.result = True
    #     r_obj.score = score
    #     r_obj.message = "Partially Correct: S=" + str(S)

    r_obj.result = True
    r_obj.score = score
    r_obj.message = "S=" + str(S)

# End of BODY
        

# Start of TAIL
class TestStruct:
    def __init__(self):
        self.testcase_id = 0
        self.testcase_input_path = ""
        self.testcase_output_path = ""
        self.testcase_expected_output_path = ""
        self.testcase_error_path = ""
        self.metadata_file_paths = []
        self.submission_code_path = ""
        self.submission_language = ""
        self.testcase_result = False
        self.testcase_signal = 0
        self.testcase_time = 0.0
        self.testcase_memory = 0
        self.data = ""


class ResultStruct:
    def __init__(self):
        self.result = False
        self.score = 0.0
        self.message = ""


def read_input_json(json_file_path, t_obj):
    file_obj = open(json_file_path, "r")
    json_file_contents = file_obj.read()
    
    root = {}
    try:
        root = json.loads(json_file_contents)
    except ValueError:
        return 1

    try:
        # Read values
        t_obj.testcase_id = root["testcase_id"]
        t_obj.testcase_input_path = root["input_file_path"]
        t_obj.testcase_output_path = root["output_file_path"]
        t_obj.testcase_expected_output_path = root["expected_output_file_path"]
        t_obj.testcase_error_path = root["error_file_path"]
        t_obj.metadata_file_paths = root["metadata_file_paths"]
        t_obj.submission_code_path = root["submission_code_path"]
        t_obj.submission_language = root["submission_language"]
        t_obj.testcase_result = root["testcase_result"]
        t_obj.testcase_signal = root["testcase_signal"]
        t_obj.testcase_time = root["testcase_time"]
        t_obj.testcase_memory = root["testcase_memory"]
        t_obj.data = root["data"]
    except KeyError:
        return 1

    return 0


def write_result_json(r_obj):
    root = {
        "custom_result" : int(r_obj.result),
        "custom_score"  : max((r_obj.score if (r_obj.score <= 1.0) else 1.0), 0),
        "custom_message": r_obj.message if (len(r_obj.message) <= 4096) else r_obj.message[0:4095]
    }

    print(json.dumps(root))


if __name__ ==  "__main__":
    # Input parameters
    t_obj = TestStruct()
    # Result parameters
    r_obj = ResultStruct()

    if len(sys.argv) < 2:
        write_result_json(r_obj)
        sys.exit(1)

    # Decode input JSON
    failure = read_input_json(sys.argv[1], t_obj)
    # Incase input JSON was malformed or not existent
    if failure != 0:
        r_obj.message = "Unable to read input json"
        write_result_json(r_obj)
        sys.exit(2)

    #Run the custom checker evaluator
    run_custom_checker(t_obj, r_obj)

    # Encode result JSON
    write_result_json(r_obj)
    sys.exit(0)
# End of TAIL
