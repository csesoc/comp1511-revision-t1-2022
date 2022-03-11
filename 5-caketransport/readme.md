## Challenge Name

Cake Transport

## Problem Statement

Alex, the world-renowned cake chef, has baked two giant cakes and placed them on a very long table, which can be thought of as a 2D plane. Each cake can be represented by an axis-aligned polygon on that table. You are guaranteed that the two cakes are disjoint, and that they do not intersect themselves. Alex has baked these cakes for two customers, sitting at the top and bottom of the table. One cake will be sent up to the top of the table, the other will be sent down to the bottom of the table. However, Alex does not know which cake will go up and which will go down, and so wants to make sure that it is possible to get the cakes to the customers in both scenarios.

Determine for Alex if the cakes can slide freely up and down without collision. It counts as a collision even if the cakes will touch at a single point.

## Input Format

The first line of input contains two integers, $N$ and $M$.

The second and third lines describe the first cake. 
In particular, the second line will contain $N$ integers, the $i$-th of which is $x[i]$, the $i$-th x-coordinate of the first cake.
The third line will contain $N$ integers, the $i$-th of which is $y[i]$, the $i$-th y-coordinate of the first cake.

The fourth and fifth lines describe the second cake. 
In particular, the fourth line will contain $M$ integers, the $j$-th of which is $x[j]$, the $j$-th x-coordinate of the second cake.
The fifth line will contain $M$ integers, the $j$-th of which is $y[j]$, the $j$-th y-coordinate of the second cake.

## Constraints

For all cases:

- $1 \leq N, M \leq 1,000$.
- $-1,000,000,000 \leq x[i], y[i], x[j], y[j] \leq 1,000,000,000$ for all $i$ and $j$.

## Output Format

If the two cakes will collide, then you should output `Collision!`. If they will not collide, then you should output `No Collision!`.

## Sample Input 0


## Sample Output 0


## Explanation 0

Since the two cakes can slide freely up and down, the correct output is `No Collision!`.

## Sample Input 1

## Sample Output 1

## Explanation 1

It is possible for the first cake to slide up and the second to slide down, however it is not possible for the first cake to slide down and the second to slide up. 
Therefore the correct output is `Collision!`
