## Challenge Name

Magic Eraser

## Problem Statement

You love showering. Unfortunately, you've been neglecting your shower cleaning duties and now there's mould on the walls! 

Fortunately, you have a magic eraser that cleans mould really well. It's in the shape of a cube with each side being $X$ centimetres long. The surface area of the cube isn't large enough to clean all your walls, so you decide to subdivide the cube into smaller cubes of length $Y$ centimetres.

What is the combined surface area of the new cubes?

## Input Format

The first line of input contains the integer $X$, the side length of your original magic eraser in centimetres.

The second line contains the integer $Y$, the side length of your smaller cubes in centimetres.

## Constraints

- $2 \leq X \leq 500$.
- $1 \leq Y < X$.
- $X$ is a multiple of $Y$.

## Output Format

Output a single integer, the total surface area of all the smaller cubes in square centimetres.

*Warning:* If you are using Python, be careful to use integer division (`//`) instead of floating point division (`/`), otherwise your answer may have a decimal point in it.

## Sample Input 0

input00.txt

## Explanation 0

Your original magic eraser is subdivided into 8 smaller cubes, each with a side length of 1 centimetre (See `diagram.png`). Therefore, since each cube has 6 sides, the total surface area of the cubes is 48 square centimetres.

