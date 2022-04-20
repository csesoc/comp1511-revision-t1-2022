// Scissors Paper Rock
// COMP1511 Exam Prep n' Chill (T1, 2022)
// Written by Jeffrey Yao for CSESoc Education

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SCISSORS 'S'
#define PAPER 'P'
#define ROCK 'R'
#define MAX_TURNS 3
// Store moves in char array of length 6.
// Why 7: Array length includes turns (T), spaces between turns (S),
// the EOF character (\n) AND the null terminator (\0).
// | T | S | T | S | T | \n | \0 |
#define MAX_LENGTH 7

struct player
{
    int points;
    char moves[MAX_LENGTH];
};

struct moves_valid
{
    bool p1;
    bool p2;
};

bool check_move(struct player player);
bool player_won(
    struct player active, struct player player1, struct player player2, int i);
void print_winner(struct player player1, struct player player2);

int main(void)
{
    struct player player1;
    struct player player2;
    player1.points = 0;
    player2.points = 0;
    struct moves_valid moves_valid;

    // Scan in player moves.
    fgets(player1.moves, sizeof(player1.moves), stdin);
    fgets(player2.moves, sizeof(player2.moves), stdin);

    // Validate moves.
    moves_valid.p1 = check_move(player1);
    moves_valid.p2 = check_move(player2);

    if (!(moves_valid.p1 && moves_valid.p2))
    {
        printf("Moves invalid!");
        // Terminate with error.
        return 0;
    }

    // For each turn, check who won.
    for (int i = 0; i < MAX_LENGTH; i += 2)
    {
        bool is_draw = player1.moves[i] == player2.moves[i];
        bool player1_won = player_won(player1, player1, player2, i);

        if (is_draw)
        {
            // No points for turn. Move to next turn.
            continue;
        }
        else if (player1_won)
        {
            player1.points++;
        }
        else
        {
            player2.points++;
        }
    }

    print_winner(player1, player2);

    return 0;
}

// Checks if all moves for player are valid.
bool check_move(struct player player)
{
    if ((player.moves[0] == SCISSORS || player.moves[0] == PAPER
            || player.moves[0] == ROCK)
        && (player.moves[2] == SCISSORS || player.moves[2] == PAPER
            || player.moves[2] == ROCK)
        && (player.moves[4] == SCISSORS || player.moves[4] == PAPER
            || player.moves[4] == ROCK))
    {
        return true;
    }
    else
    // Characters other than S, P and R have been entered. Moves invalid.
    {
        return false;
    }
}

// In the case that the turn isn't a draw, check if the specified (active)
// player won.
bool player_won(
    struct player active, struct player player1, struct player player2, int i)
{
    // Rock wins against scissors, scissors wins against paper, paper wins
    // against rock.
    // Letters correspond to integer ASCII codes in C. This means that we can
    // 'add' characters together, or their ASCII code values, to check for the
    // presence of specific combinations. (i.e. R + S = 165)
    // See the ASCII table here: http://sticksandstones.kstrom.com/appen.html
    if ((player1.moves[i] + player2.moves[i] == ROCK + SCISSORS
            && active.moves[i] == ROCK)
        || (player1.moves[i] + player2.moves[i] == SCISSORS + PAPER
            && active.moves[i] == SCISSORS)
        || (player1.moves[i] + player2.moves[i] == PAPER + ROCK
            && active.moves[i] == PAPER))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Prints winner after game finished.
void print_winner(struct player player1, struct player player2)
{
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
}