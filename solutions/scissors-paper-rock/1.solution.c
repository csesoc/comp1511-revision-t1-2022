#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns 1 if valid move, 0 if not
int validmove(char a) { return (a == 'S' || a == 'R' || a == 'P'); }

// Returns 0 if draw, 1 if p1 wins and -1 if p1 loses
int wld(char p1, char p2)
{
    if (p1 == p2)
        return 0;
    if ((p1 == 'S' && p2 == 'P') || (p1 == 'P' && p2 == 'R')
        || (p1 == 'R' && p2 == 'S'))
        return 1;
    return -1;
}

int main(void)
{
    char p1[10];
    char p2[10];

    // We only need to keep track of player 1's score
    int p1Score = 0;

    // Collect input from stdin
    fgets(p1, 10, stdin);
    fgets(p2, 10, stdin);

    // Check each move
    // Note incrementing by 2 so we are ignoring where there should be spaces
    // In thahhis case, the string RLPUS will still be considered valid
    for (int i = 0; i < 5; i += 2)
    {
        if (!validmove(p1[i]) || !validmove(p2[i]))
        {
            printf("Moves invalid!\n");
            return 1;
        }
        p1Score += wld(p1[i], p2[i]);
    }

    // If p1Score is 0, draw, greater than 0 we have won else lost
    if (p1Score == 0)
        printf("It's a draw!\n");
    if (p1Score < 0)
        printf("Player 2 won!\n");
    if (p1Score > 0)
        printf("Player 1 won!\n");
}
