// Scissors Paper Rock
// Written by Jeffrey Yao on 3/03/2022
// Comments used throughout code to explain solution.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Define scissors, paper and rock as constants for clarity.
#define SCISSORS 'S'
#define PAPER 'P'
#define ROCK 'R'
// Miscallaneous constants
#define MAX_TURNS 3

// Define each player's data as a struct.
struct player
{
    // If turn won, increment points by 1.
    int points;
    // Store moves in array.
    char move[3];
};

void checkMove(bool *movesValid, struct player player);

int main(void)
{

    struct player player1;
    struct player player2;
    player1.points = 0;
    player2.points = 0;
    bool *movesValid = false;

    // TODO: Extract block to function scanMoves
    // Scan in player moves
    scanf("%c %c %c", &player1.move[0], &player1.move[1], &player1.move[2]);
    checkMove(&movesValid, player1);
    scanf("%c %c %c", &player2.move[0], &player2.move[1], &player2.move[2]);
    checkMove(&movesValid, player2);
    // Terminate program if invalid characters entered.
    assert(movesValid);

    for (int i = 0; i < MAX_TURNS; i++)
    {
        // A naive solution would be to hardcode each case. Instead, add each
        // player's moves to check combination present. We can check for the
        // presence of a certain combination by checking the sum of their ASCII
        // values.
        // Case 1: Draw
        if (player1.move[i] = player2.move[i])
        {
            // No points.
            break;
        }
        // Case 2: Any other combination
        if (player1.move[i] + player2.move[i] == ROCK + SCISSORS
            || SCISSORS + PAPER || PAPER + ROCK)
        {
            // Rock beats scissors, scissors beats paper, paper beats rock.
            if (player1.move[i] == ROCK || SCISSORS || PAPER)
            {
                player1.points++;
            }
            // If Player 1 doesn't have the winning move, Player 2 must have it.
            else
            {
                player2.points++;
            }
        }
    }

    if (player1.points > player2.points)
    {
        printf("Player 1 won!");
    }
    else if (player2.points > player1.points)
    {
        printf("Player 2 won!");
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}

// Checks if all moves are valid.
void checkMove(bool *movesValid, struct player player)
{
    if ((player.move[0] == SCISSORS || PAPER || ROCK)
        && (player.move[1] == SCISSORS || PAPER || ROCK)
        && (player.move[2] == SCISSORS || PAPER || ROCK))
    {
        *movesValid = true;
    }
    else
    {
        *movesValid = false;
    }
}