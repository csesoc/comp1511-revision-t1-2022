## Challenge Name

Robot Vacuum II

## Problem Statement

Marvin is a robot on the 2D coordinate grid. He accepts a sequence of instructions: `U`, `D`, `L` or `R`, which represent moving 1 unit up, down, left and right respectively, as shown in the diagram below.

Being a paranoid android, he has the option to delete any of his instructions before he executes the remaining instructions in their original order. By strategically choosing which instructions to delete, what is the furthest distance Marvin can reach from his starting position during execution, while ensuring he returns to his starting position at the end?

By distance we are referring to Manhattan distance, which is the sum of the horizontal and vertical distances. 

## Input Format

The first line of input contains the integer $N$, the number of instructions.

The second line will contain a string of $N$ characters, where each one character is either `U`, `D`, `L` or `R`.

## Constraints

For all test cases:

- $1 \le N \le 100000$.

Additionally:

- For test cases worth 50%, $1 \le N \le 1000$.

## Output Format

Output a single integer, the maximum Manhattan distance from the starting position after removing some instructions.

## Sample Input 0

input00.txt

## Explanation 0

After removing some instructions, he may obtain the new sequence of instructions: `UR URD DL`. If he does this, Marvin's furthest Manhattan distance from the starting position during his journey is 3, which is the maximum possible.