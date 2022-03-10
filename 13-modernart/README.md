## Challenge Name

Modern Art

## Problem Statement

To take a break from coding, you've decided to have a crack at making a beautiful painting.

In front of you is an empty canvas, which is an $R \times C$ grid of pixels.
Each pixel has a certain *goodness* value, which is an integer between $0$ and $9$ inclusive.
Having scrutinised countless pieces of modern art, you know that to create a beautiful and emotionally moving painting:

- You must paint exactly $N$ of the pixels,
- The painted pixels should form a connected region. More precisely, for every pair of painted pixels, there must exist a sequence of
  up, down, left and/or right movements to travel from one to the other, only using painted pixels along the way.
- You should try to make the sum of goodness values of the painted pixels as large as you can.

You do not have to find an optimal painting;
instead, you will receive points based on how good your painting is. See the Scoring section for details.

## Scoring

If your painting is invalid, it will score $0%$ of the points for the task.

Otherwise, TODO.

## Input Format

There is **one public testcase** for this task, which can be found somewhere TODO.

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

"MORECONSONANTS" contains 9 consonants and 5 vowels, so it has more consonants.