## Challenge Name

Robot Vacuum II

## Problem Statement

Marvin is a robot on the 2D coordinate grid. He accepts a sequence of instructions: `U`, `D`, `L` or `R`, which represent moving 1 unit up, down, left and right respectively. See `diagram.jpg`. Furthermore, he has to start at the origin, and return to the origin after completing the sequence of instructions. Being a paranoid android, he has the option to ignore any instructions and execute the new sequence of instructions in order. What is the furthest Manhattan distance from the start position at any point during execution?

(The Manhattan distance is the sum of horizontal and vertical distances.)

## Input Format

The first line of input contains the integer $N$, the number of instructions.

The following line will contain $N$ characters, which are either `U`, `D`, `L` or `R`.

## Constraints

For all test cases:

- $1 \le N \le 100000$.
- For 50% of the marks, $1 \le N \le 1000$.

## Output Format

Output a single integer - the maximum manhattan distance from the origin after removing some instructions.

## Sample Input 0

input00.txt

## Explanation 0

After removing some instructions, he may arrive at this new sequence of instructions: `U  URD DL`. See `diagram2.jpg`. Note that Marvin is starting and ending at the origin.

The maximum Manhattan distance of this path is . It can be shown that this is the maximum possible manhattan distance.