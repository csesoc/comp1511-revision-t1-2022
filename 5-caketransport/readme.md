## Challenge Name

Cake Transport

## Problem Statement

Alex, the world-renowned cake shef, has baked two giant cakes and placed them on a very long table, which can be thought of as a 2D plane. Each cake can be represented by an axis-aligned polygon on that table. You are guaranteed that the two cakes are disjoint, and that they do not intersect themselves. Alex has baked these cakes for two customers, sitting at the top and bottom of the table. One cake will be sent up to the top of the table, the other will be sent down to the bottom of the table. However, Alex does not know which cake will go up and which will go down, and so wants to make sure that it is possible to get the cakes to the customers in both scenarios.

Determine for Alex if the cakes can slide freely up and down without collision. It counts as a collision even if the cakes will touch at a single point.

## Input Format

The first line of input contains two integers, $N$ and $M$.

The next $N$ lines of input will represent the corners of the first cake, in order. The $i$th line will contain $x_i$ and $y_i$, the coordinates $ith$ corner.

The next $M$ lines of input will represent the corners of the second cake, in order. The $j$th line will contain $x_j$ and $y_j$, the coordinates $jth$ corner.

## Constraints

$1 \leq N, M \leq 1,000$
$-1,000,000,000 \leq x_i, y_i, x_j, y_j \leq 1,000,000,000$

## Output Format

If the two cakes will collide, then you should output `Collision!`. If they will not collide, then you should output `No Collision!`.

## Sample Input 0


## Sample Output 0


## Explanation 0

Since the two cakes can slide freely up and down, the correct output is "No Collision!".

## Sample Input 1

## Sample Output 1

## Explanation 1

Since the two cakes cannot slide freely up and down, the correct output is "Collision!"
