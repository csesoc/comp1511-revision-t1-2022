# COMP1511 Exam Prep Revision Session

Raw files for the event's exam practice questions. Same structure as what is uploaded on hackerrank. Note that some of this info may be irrelevant to COMP1511 Exam Prep questions because these instructions are copied from the IMC x CSESoc x CPMSoc Coding Contest event.

## How to add questions
1. Create a new folder in this repository with the question title
2. Create a `README.md` file in the folder containing the problem's information (matches what's needed for HackerRank):
   - Challenge Name
   - Problem Statement
   - Input Format
   - Constraints
   - Output Format
   - Sample Cases and Explanations
3. If your problem used DSL to generate starter code, create a `dsl.txt` file in the folder containing the raw [DSL](https://help.hackerrank.com/hc/en-us/articles/360008561014) for the problem's starter code
4. Create a subfolder called `tests/` which will contain the problem test cases, arranged like so:
   - For each test case, create two files called `inputXX.txt` and `outputXX.txt` where `XX` is a number from 0 to 99 (for example `input00.txt` or `input42.txt`)
   - Place the input files in the `input/` subfolder and the output files in an `output/` subfolder.
5. Create a solution file if you have one as well. The main solution file is `solution.c` and any other solution files should be of the form `solution-*.c`.

## Writing generators
A sample generator is at `generator_example.py` in the repository's root directory. Copy it over and then modify it to generate your data, if you wish.

## Testing
Test all solutions named `solution*.py`, `solution*.c` or `solution*.cpp` by going into the problem directory and running `sh ../test_solutions.sh` or `sh ../test_solutions_checker.sh` depending on whether there is a checker.

A simple question layout is available in the `sample-doss` folder.
