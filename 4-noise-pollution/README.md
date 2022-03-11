## Challenge Name

Noise Pollution

## Problem Statement

There are $N$ people who will attend sporting matches.
Each person will watch some of the matches, and has a certain loudness.

For each sporting match, who is the loudest person attending?

## Input Format

The first line of input contains the integer $N$, the number of people attending the matches.

Following this are the descriptions of each person.
The first line of each person description contains their name as a string, then two integers: their loudness, and the number of matches they will attend.
The following $N$ lines each contain a distinct string, representing a match that the person attends.

## Constraints

For all test cases:

- $1 \le N \le 100$.
- There are at most 100 matches in total.
- Each person's name is unique.
- Each person's loudness is a unique integer between 0 and 1000 inclusive.
- Each person watches at most 50 matches.
- All strings are at most 10 characters, and only contain lowercase letters.

## Output Format

Output one line for each sporting match (any order will do). Each line should be of the form:
`In [sporting match], [person] is the loudest!`

## Sample Input 0

input00.txt

## Explanation 0

In the Boxing and NRL matches, Pat is the loudest at a volume of 1000. The Cricket match has only 1 audience member, Isaiah, so he is the loudest at a volume of 0. In Soccer, Angus is the loudest at a volume of 20. In Tennis, Ryan is the loudest at a volume of 50.