## Challenge Name

Bishops Move

## Problem Statement

Given a 2D 8x8 chessboard with some starting (chess) pieces and the location of a bishop starting square and desired ending square, print the shortest path of a bishop from the starting square to the ending square. If there are multiple shortest paths, print them all. The shortest path is determined by the least number of moves. You are given that there won't be more than N starting pieces, and you may assume these pieces remain fixed in place and won't ever move.

The movement of the bishop is subject to 4 simple constraints:

1. the bishop cannot land on a square it has already landed on in the past,

2. bishops can never move past any starting piece in its path,

3. bishops can never move past any edge of the chessboard,

4. if not subject to the above constraints, bishops can move as many squares from its position in any diagonal direction. This follows the usual movement pattern of a normal chess bishop.

## Input Format

Your first line will contain the starting square of form $x_sy_s$, where $x_s$ is a letter between a and h inclusive, and $y_s$ is a number between 1 and 8 inclusive. (If you're unfamiliar with this notation, search up **chess algebraic notation**). For example this could be **a8** or **h1** or **e4**.

Your second line will contain the desired ending square of form $x_ey_e$ using the same notation as above.

Your third line will contain an integer $N$ denoting how many other starting pieces there are on the board. You are guaranteed none of these pieces will be on the bishop's starting square.

The next N lines all contain coordinates of form $x_iy_i$ denoting the position of each of the N starting pieces.

## Constraints

$x$ is a letter between a and h inclusive, and $y$ is a number between 1 and 8 inclusive

## Output Format

Output the string **No possible path** if there is no way the bishop can move from the starting square to the ending square. Else, if there are $M$ paths from the starting square to the ending square, output $M$ lines of **sorted** paths. A path is sorted first by its letter coordinate and then by its number coordinate, where a 'smaller' letter/number is considered higher in the list respectively.

## Sample Input

input00.txt
**Mark this case as sample, but still give it a weight, so noobs still get points just for getting sample right.\***

## Explanation

The bishop can move from $a_1$ to $h_8$ in exactly one move.
