## Challenge Name

Mountains

## Problem Statement

There is a mountain range which consists of $N$ mountains in a line, numbered 0 to $N-1$ from left to right. 
The $i$-th mountain has a height of $H[i]$.

For each mountain, there is a reward $R[i]$ (in dollars) you get if you climb that mountain, where $R[i]$ is 1, 0 or -1. 
A negative reward means you must pay to climb the mountain!

You will do a walk of the mountains, where a walk is defined as follows:

- You first pick a starting mountain $S$, and climb onto that mountain. The effort required to do this is $H[S]^2$.
- If you are on some mountain $i$, you can climb onto the adjacent mountain $i-1$ (if $i > 0$). The effort required to do this is $(H[i]-H[i-1])^2$.
- If you are on some mountain $i$, you can climb onto the adjacent mountain $i+1$ (if $i < N-1$). The effort required to do this is $(H[i]-H[i+1])^2$.
- You can finish your walk on any mountain, at which point you climb off the mountain. Assuming you finish on mountain $E$, the effort required to do this is $H[E]^2$.

For each mountain $i$, you receive the reward $R[i]$ if you climb onto that mountain during your walk. **If you climb onto the same mountain more than once during your walk, you only receive the reward once**.

You want to make at least 1 dollar. 
What is the minimum effort required to do this?

## Input Format

The first line of input will contain the integer $N$, the number of mountains.

The second line of input will contain $N$ integers, the $i$-th of which is $H[i], the height of the $i$-th mountain.

The third line of input will contain $N$ integers, the $i$-th of which is $R[i], the reward you get for climbing the $i$-th mountain.

## Constraints

For all test cases:

- $1 \le N \le 100000$.
- $1 \le H[i] \le 1000000$ for all $i$.
- R[i] is 1, 0 or -1 for all $i$.
- R[i] = 1 for at least one $i$.

Note that $H[i]^2$ can overflow a 32-bit integer (e.g. an `int` in C).
We recommend using 64-bit integers (e.g. a `long long` in C).
If you are using python, then this is not an issue.

Additionally:

- For test cases worth 25%, $N \le 20$.
- For test cases worth another 25%, $N \le 1000$.
- For test cases worth 50%, including 50% of the aforementioned cases, $R[i]$ is 0 and 1 for all $i$. [Angus: Maybe remove this?]

## Output Format

Output a single integer: the minimum effort required to make at least 1 dollar.

## Sample Input 0

input00.txt

## Explanation 0


## Sample Input 1

input01.txt

## Explanation 1

## Sample Input 2

input02.txt

## Explanation 1

