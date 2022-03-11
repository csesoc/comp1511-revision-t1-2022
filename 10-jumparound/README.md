## Challenge Name

TreeTown

## Problem Statement

Tommy is going on a holiday to his favourite tourist destination, TreeTown.

TreeTown consists of $N$ sites, and $N-1$ two-way roads, such that from every site,
every other site can be reached via some sequence of roads.
The $i$th road connects site $a[i]$ to site $b[i]$.

On each day of his holiday, Tommy will visit one site, such that:

- On the first and last days, he visits site $0$.
- On any two consecutive days, the sites he visits on those days are distinct and connected by a road.
- For all $i$, he visits site $i$ at least $x[i]$ times, over the entire holiday.

Subject to these constraints, what is the smallest possible number of days that Tommy's holiday can last?

## Input Format

The first line of input contains the integer $N$, the number of sites in TreeTown.

The second line contains $N$ integers, the $i$th of which is $x[i]$.

The third line contains $N-1$ integers, the $i$th of which is $a[i]$.

The fourth line contains $N-1$ integers, the $i$th of which is $b[i]$.


## Constraints

For all test cases:

- $2 \le N \le 100000$.
- $1 \le a[i] < b[i] \le N$ for all $i$.
- $1 \le x[i] \le 10000$ for all $i$.

Additionally:

- For test cases worth 50%, $a[i]=i$ and $b[i]=i+1$, for all $i$. In other words, TreeTown is a line. See Sample Input 1 for an example.

## Output Format

Output a single integer, the smallest possible number of days that Tommy's holiday can last.

## Sample Input 0

input00.txt

## Explanation 0

The diagram depicts the sites and roads of TreeTown.
The large numbers inside the circles are the values of $x[i]$,
and the small numbers outside the circles are the indices $i$ of the sites.

A valid holiday lasting 15 days visits the following sites in order:
$0, 2, 0, 2, 0, 3, 4, 3, 1, 3, 4, 3, 0, 2, 0$.
No shorter valid holidays exist.

## Sample Input 1

input01.txt

## Explanation 1

In this case, TreeTown is a line. One shortest valid holiday visits the following sites in order:
$0, 1, 0, 1, 2, 3, 2, 1, 2, 1, 0, 1, 0$.