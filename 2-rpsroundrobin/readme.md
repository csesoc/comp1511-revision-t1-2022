## Challenge Name

RPS Round Robin

## Problem Statement

Jack loves playing RPS. Today, he is facing off against the world champion RPS robot, the Robust Programmed System. What he doesn't know is that the robot just plays Rock, then Paper, then Scissors over and over again.

They will face off in $N$ rounds of RPS. In the $i$th round (starting from 1), the winner of the round gets $i$ bitcoins. Given Jack's sequence of moves, determine his total winnings.

## Input Format

The first line of input will contain a single integer, $N$.

The second line of input will contain $N$ characters

*Warning:* Don't forget about the \n character at the end of the first line of input

## Constraints

For all test cases:

- $1 \le N \le 100$

## Output Format

Output a single integer, Jack's total winnings

## Sample Input 0

input00.txt

## Explanation 0

Here, the robot throws the sequence "RPSRPSR". Hence, Jack wins 1 + 2 + 3 + 0 + 0 + 6 + 7 = 19 bitcoins
