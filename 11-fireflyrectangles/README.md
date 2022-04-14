## Challenge Name

Firefly Rectangles

## Problem Statement

Poppy loves to look at fireflies, and loves how they make all kinds of pretty shapes in the sky. 

Poppy has taken a photo of $N$ fireflies in the sky, which can be represented as distinct points in the 2D plane.
The $i$th firefly is at coordinates $(x[i], y[i])$.

How many rectangles (not necessarily axis-aligned) exist whose four vertices all lie on distinct fireflies?

## Input Format

The first line of input contains a single integer, $N$.

The second line of input will contain $N$ integers, the $i$th of which is $x[i]$.

The third line of input will contain $N$ integers, the $i$th of which is $y[i]$.

## Output Format

Output a single integer, the number of rectangles which can be formed from four distinct fireflies in the photo.

## Constraints

For all test cases:

- 1 \leq $N$ \leq 1000.
- 0 \leq $x[i]$, $y[i]$ \leq 10000.

Additionally:

- For test cases worth 25%, $N \le 50$.

## Sample Input 0

input00.txt

## Explanation 0

The locations of the 6 fireflies are shown in the diagram.
There are 2 rectangles whose vertices all lie on fireflies.