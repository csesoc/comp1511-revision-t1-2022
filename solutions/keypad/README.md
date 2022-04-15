## Challenge Name

Typing Champ

## Problem Statement
Joseph uses his phone so often that he remembers how his fingers move to type in
the six-digit passcode, but not the passcode itself. The keypad has the following layout.

[diagram]

His finger starts in the top left, and then his finger movements can be
described by a sequence of actions. Each action is either a key press, or
a movement up, down, left or right one position.

Given the sequence of actions, what is Joseph's passcode?

## Input Format

The first line of input contains a single integer $N$, the number of actions in the sequence.
The second line contains a string of $N$ characters, representing the sequence of moves:

- `L` stands for a leftwards movement.
- `R` stands for a rightwards movement.
- `U` stands for a upwards movement.
- `D` stands for a downwards movement.
- `P` stands for a press of the key his finger is currently over.

## Constraints
For all test cases:

- $6 \leq N \leq 100$.
- Each character is either `L`, `R`, `U`, `D`,  or `P`.
- The character `P` appears exactly six times.

Additionally:

- For test cases worth 50%, there are no `U` or `D` moves.

## Output Format

Output a single string of digits, Joseph's six-digit passcode.

## Sample Input

input00.txt

## Explanation

The diagram depicts the sequence of finger movements.

[image Keypadsol.png]
