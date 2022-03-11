## Challenge Name

Robot Vacuum II

## Problem Statement

Marvin is a robot, who accepts a sequence of instructions: `U`, `D`, `L` or `R`, which represent up, down, left and right respectively. Being a paranoid android, it has the option to remove any instructions and execute the new sequence of instructions in order. If it starts and ends at the same position, what is the furthest distance that it can reach?

For simplicity, distance is defined as the manhattan distance, which is the sum of x and y distances. In other words, $manhattan distance = |x| + |y|$


## Input Format

The first line of input contains the integer $N$, the number instructions.

The following line will contain $N$ characters, which are either U, D, L or R.

## Constraints

For all test cases:

- $1 \le N \le 100000$.
- For 50% of the marks, $1 \le N \le 1000$.

## Output Format

Output a single integer - the maximum manhattan distance from the origin after removing some instructions.

## Sample Input 0

input00.txt

## Explanation 0

After removing some instructions, it may arrive at this new sequence of instructions: `U  URD DL`. See `diagram.jpg`, Marvin starts and ends at the square.

Marvin reaches a distance of 2 + 1, and returns to the origin. It can be shown that this is the maximum possible manhattan distance.