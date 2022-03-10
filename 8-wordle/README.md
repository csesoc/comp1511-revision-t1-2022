## Challenge Name

Wordle

## Problem Statement

For the purpose of this question, the rules of Wordle are as follows:

- There are $N$ allowed words, which are all 5 letters long and have **no repeated letters**. That is, each word contain 5 different letters.
- One of these words is the **answer**.
- You can make a **guess**, where you guess one of the allowed words. For each letter in your guess, you are told if this letter appears in the same spot in the answer (green, repesented by `G`), a different spot in the answer word (yellow, represented by `Y`), or does not appear in the answer word (grey, represented by `.`).

For example, if the correct word is `MONTH`, and you guessed `CLOTH`, then the response would be `..YGG`, because

- `C` does not appear in `MONTH`, giving `.`
- `L` does not appear in `MONTH`, giving `.`
- `O` does appear in `MONTH`, but in a different position to where it appears in `CLOTH`, giving `Y`
- `T` appears in `MONTH`, in the same position as it appears in `CLOTH`, giving `G`
- `H` appears in `MONTH`, in the same position as it appears in `CLOTH`, giving `G`

Note that these are the same as the official wordle rules, except that in the real game repeated letters are allowed.

You have made $K$ guesses so far.
Given these guesses and the reponses to these guesses, which words could be the answer?

## Input Format

The first line of input contains the integer $N$, the number of allowed words.

The next $N$ lines contain the allowed words. 
Each line contains one 5-letter uppercase word with no repeated letters. 
All $N$ words are different.

The next line contains $K$, the number of guesses you made.
Each guess is described by two lines. 
The first line contains the word you guessed, which is one of the allowed words.
The second line contains the response to this guess, which is a 5-letter string consisting of `G`, `Y` and `.`.

## Constraints

For all test cases:

- $1 \le N \le 1000$.
- $1 \le K \le 5$

## Output Format

Output the possible answers, one per line, in the same order as they appear in the input.

You are guaranteed that there is at least one possible answer.

## Sample Input 0

input00.txt

## Explanation 0

Both `BREAD` and `TREAD` give the response `YY.YY` when the guess is `EAGER`.

## Sample Input 1

input01.txt

## Explanation 1

Both `ABCDE` and `EDCBA` give the response `..G..` when the guess is `FOCUS`.

Both `ABCDE` and `ABODE` give the response `G..GG` when the guess is `ASIDE`.

Hence, `ABCDE` is the only word that is consistent with both guesses.