# Pally's Palindromes Challenge


## Problem Statement

Pally's favourite word is `saippuakivikauppias` which is Finnish for a dealer in lye (caustic soda). It's the longest known palindromic word!

A palindrome is a word where the letters read backwards, give the same word. Another example is the word `racecar`.

Help Pally out by writing a program that which reads a string and tests if it is a palindrome.

## Input Format

The only line of input is a string in which you will check if the string is a palindrome.

## Constraints
Do not use `scanf` - use fgets to read the string.

Note, your program needs to read only one string - it doesn't have to read until end of input.

You can assume lines contain at most `4096` characters.

Checking the palindrome should be case insensitive, i.e. `a` should be treated as the same letter as `A`.

## Output Format

If a string is a palindrome, print `String is a palindrome`.

If a string is not a palindome, print `String is not a palindrome`.

## Sample Input 0
`saippuakivikauppias`

## Sample Output 0
`String is a palindrome`

## Explanation 0

This input is a palindrome

## Sample Input 1
`axolotl`

## Sample Output 1
`String is not a palindrome`

## Explanation 1

This input was not a palindrome because it did not read same forwards and backwards.

