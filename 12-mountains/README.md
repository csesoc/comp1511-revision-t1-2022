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

You would like your total reward to be at least 1 dollar. 
What is the minimum effort required to do this?

## Input Format

The first line of input will contain the integer $N$, the number of mountains.

The second line of input will contain $N$ integers, the $i$-th of which is $H[i]$, the height of the $i$-th mountain.

The third line of input will contain $N$ integers, the $i$-th of which is $R[i]$, the reward you get for climbing the $i$-th mountain.

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
- For test cases worth 50%, including 50% of the aforementioned cases, $R[i]$ is 0 and 1 for all $i$.

## Output Format

Output a single integer: the minimum effort required to make at least 1 dollar.

## Sample Input 0

input00.txt

## Explanation 0

In this case:

- You can start on mountain 1. You receive a reward of 0 and the effort is $1^2 = 1$.
- You can climb to the adjacent mountain 2. You receive a reward of 1 and the effort is $(4-1)^2 = 9$.
- You can climb to the adjacent mountain 3. You receive a reward of 0 and the effort is $(4-3)^2 = 1$.
- You finish on mountain 3. The effort is $3^2 = 9$.

Your total effort is $1+9+1+9 = 20$ and your reward is $0+1+0 = 1$. This is the minimum effort possible to get a reward of at least 1.
This path is shown in the image below.
[image: sample0.png]

## Sample Input 1

input01.txt

## Explanation 1

In this case:

- You can start on mountain 1. You receive a reward of -1 and the effort is $5^2 = 25$.
- You can climb to the adjacent mountain 0. You receive a reward of 1 and the effort is $(6-5)^2 = 1$.
- You can climb back to the adjacent mountain 1. You don't receive a reward (because you have visitied this mountain before) and the effort is $(6-5)^2 = 1$.
- You can climb to the adjacent mountain 2. You receive a reward of 1 and the effort is $(6-5)^2 = 1$.
- You can climb back to the adjacent mountain 1. You don't receive a reward (because you have visitied this mountain before) and the effort is $(6-5)^2 = 1$.
- You finish on mountain 1. The effort is $5^2 = 25$.

Your total effort is $25+1+1+1+1+25 = 54$ and your reward is $-1+1+1 = 1$. This is the minimum effort possible to get a reward of at least 1.
This path is shown in the image below.
[image: sample1.png]

## Sample Input 2

input02.txt

## Explanation 2

In this case:

- You can start on mountain 5. You receive a reward of 1 and the effort is $2^2 = 4$.
- You finish on mountain 5. The effort is $2^2 = 4$.

Your total effort is $4+4 = 8$ and your reward is $1$. This is the minimum effort possible to get a reward of at least 1.
This path is shown in the image below.
[image: sample2.png]

