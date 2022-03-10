## Challenge Name

Modern Art

## Problem Statement

To take a break from coding, you've decided to have a go at making a beautiful painting.

In front of you is an empty canvas, which is an $R \times C$ grid of pixels.
Each pixel has a certain *goodness* value, which is an integer between $0$ and $9$ inclusive.
Having scrutinised countless pieces of modern art, you know that to create a beautiful and emotionally moving painting:

- You must paint exactly $N$ of the pixels,
- The painted pixels should form a connected region. More precisely, for every pair of painted pixels, there must exist a sequence of
  up, down, left and/or right movements to travel from one to the other, only using painted pixels along the way.

Under these constraints, you should try to maximise $S$, which is defined as
the sum of goodness values of the painted pixels.

You do not have to find an optimal painting;
instead, you will receive points based on how large the value of $S$ you achieve is.

## Scoring

If your painting is invalid, your submission will score $0\%$ of the points for the task.

Otherwise, your submission will score $\min (1, \exp(0.0015 (S-7500))) \times 100\%$ of the points for the task,
where $S$ is the sum of goodness values of the painted pixels in your painting.

## Input Format

There is **one public input case** which counts for this task, which is Sample Input 1.

The first line of input contains three integers: $R$, $C$ and $N$.

The next $R$ lines each contain a string of $C$ digits.
The $j$th digit in the $i$th line represents the goodness of the pixel in
the $i$th row of the $j$th column of the canvas.

## Constraints

- $R = 100$.
- $C = 100$.
- $N = 1000$.
- Each digit in the grid was chosen at random uniformly.

## Output Format

For this task, **do not submit any code**.
You should submit an $R \times C$ grid of characters.
The $j$th character in the $i$th row should be a `#` if the pixel is painted, and a `.` otherwise.

## Sample Input 0

input00.txt

## Explanation 0

For this input case, if the indicated cells are painted, then $S=70$ is achieved.
This happens to be the highest possible value of $S$ for this input.

## Sample Input 1

input01.txt

## Explanation 0

This is the single public input case which counts for this task.