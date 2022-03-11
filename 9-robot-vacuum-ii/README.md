## Challenge Name

Robot Vacuum II

## Problem Statement

You are given a sequence of instructions U, D, L or R.
You are to remove a set of instructions and execute the new sequence of instructions in order.
What is the furthest you can be from the origin by manhattan distance during your journey, but still get back to where you started by the end? The manhattan distance is `x distance + y distance`


## Input Format

The first line of input contains the integer $N$, the number instructions.

The following line will contain $N$ characters, which are either U, D, L or R.

## Constraints

For all test cases:

- $1 \le N \le 100000$.
- The total occupancy over all matches $\le 100000$.
- All loudness values are unique non negative integers.
- No name is repeated.
- All strings are at most 10 characters, and only contain lowercase letters.

## Output Format

Output a single integer - the furthest distance manhattan distance from the origin after removing some instructions.

## Sample Input 0

input00.txt

## Explanation 0

Removing wi