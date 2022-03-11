## Challenge Name

Noise Pollution

## Problem Statement

There are $N$ people watching sporting matches. Each person will make a certain level of noise during the matches they watch. For each sporting match, who is the loudest person?

## Input Format

The first line of input contains the integer $N$, the number of people watching the matches.

The following $N$ lines will contain a name, their loudness, the number of matches they watch and a list of those matches. Each match is represented by a unique string.

## Constraints

For all test cases:

- $1 \le N \le 100$.
- There are at most 100 matches.
- Each person watches at most 50 matches.
- All loudness values are unique integers from 0 to 1000.
- No name is repeated.
- All strings are at most 10 characters, and only contain lowercase letters.

## Output Format

Output a line for each sporting match (any order will do). The line should be of the form:
`In [sport], [person] is the loudest!`

## Sample Input 0

input00.txt

## Explanation 0

NOTE: additional spacing is added for clarity.

In the boxing and nrl match, Pat is the loudest at a volume of 1000. The cricket match has only 1 audience member, Isaiah, so he is the loudest at a volume of 0. In soccer, Angus is the loudest at a volume of 20. In tennis, Ryan is the loudest at a volume of 50.