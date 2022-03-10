## Challenge Name

IMC Banner II

## Problem Statement

CPMSoc is printing a banner to advertise the competition's sponsor, IMC.
To do this, they will print a sequence of $N$ letters, each either `I`, `M`, or `C`.
They have already chosen which letters will go in some positions,
but the letters in the other positions are undecided.

Determine the maximum number of times the substring `IMC` can appear within the sequence,
if the undecided letters are picked optimally.

## Input Format

The first line of input contains the integer $N$, the number of letters in the banner.

The second line of input contains one string of length $N$, the banner so far.
Each character will be `I`, `M`, `C`, or `_`, where `_` denotes an undecided letter.

## Constraints

For all test cases:

- $1 \le N \le 100000$.

## Output Format

Output a single integer, the maximum number of times the substring `IMC` can appear.

## Sample Input 0

input00.txt

## Explanation 0

The final string could be `IMCCIMIMC`, in which case `IMC` appears as a substring 2 times,
which is the maximum possible.

## Sample Input 1

input01.txt

## Explanation 1

However the undecided letters are chosen, there is no way to make the substring `IMC` appear.