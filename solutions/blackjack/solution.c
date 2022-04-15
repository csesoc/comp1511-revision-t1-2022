#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of cards in hand
#define MAX_CARDS 5
// Maximum number of chars (including \0) in card name
#define MAX_TITLE 7

int string_to_value(char *card) {
    // Could also be done with a long if/else chain, but strtol is
    // much cleaner
    char *remainder;
    int value = strtol(card, &remainder, 10);

    if (value != 0) {
        return value;
    }

    if (strcmp(remainder, "Jack") == 0) {
        return 11;
    } else if (strcmp(remainder, "Queen") == 0) {
        return 12;
    } else if (strcmp(remainder, "King") == 0) {
        return 13;
    } else {
        return 1;
    }
}

char *value_to_string(int value) {
    char *cards[14] = { "0", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    return cards[value];
}

int hand_value(int hand[MAX_CARDS]) {
    int aces = 0;
    int sum = 0;

    int index = 0;
    while (index < MAX_CARDS) {
        int card = hand[index];

        if (card == 1) {
            aces += 1;
            sum += 11;
        } else if (card == 11 || card == 12 || card == 13) {
            sum += 10;
        } else {
            sum += card;
        }
    }

    while (sum > 21 && aces > 0) {
        sum -= 10;
        aces--;
    }

    return sum;
}

int hand_size(int hand[MAX_CARDS]) {
    int cards = 0;
    while (cards < MAX_CARDS) {
        if (hand[cards] == 0) {
            break;
        }

        cards++;
    }

    return cards;
}

int hand_finished(int hand[MAX_CARDS]) {
    int value = hand_value(hand);
    int size = hand_size(hand);

    if (value < 18 || size < 5) {
        return 0;
    }

    return 1;
}

int game_finished(int players, int hands[players][MAX_CARDS]) {
    int index = 0;

    while (index < players) {
        int *hand = hands[index];
        
        if (!hand_finished(hand)) {
            return 0;
        }

        index++;
    }

    return 1;
}

int get_card(void) {
    char *line;

    fgets(line, MAX_TITLE, stdin);
    line[strlen(line) - 1] = '\0';

    return string_to_value(line);
}

int main(void) {
    int players;
    scanf("%d", &players);

    int hands[players][MAX_CARDS];

    // Could be done with calloc(), but assuming 1511 knowledge here
    int index = 0;
    while (index < players) {
        int card_index = 0;
        while (card_index < MAX_CARDS) {
            // Add first 2 cards
            if (card_index < 2) {
                hands[index][card_index] = get_card();
            } else {
                hands[index][card_index] = 0;
            }
        }
        
        index++;
    }

    // Run the game
    int current_player = 0;

    while (!game_finished(players, hands)) {
        int *current_hand = hands[current_player];
        current_player = (current_player + 1) % players;

        if (hand_finished(current_hand)) {
            continue;
        }

        int size = hand_size(current_hand);
        current_hand[size] = get_card();
    }

    // Print results
    index = 0;
    while (index < players) {
        printf(
            "Player %d: %s %s %s %s %s\n", index + 1,
            value_to_string(hands[index][0]), value_to_string(hands[index][1]),
            value_to_string(hands[index][2]), value_to_string(hands[index][3]),
            value_to_string(hands[index][4])
        );

        index++;
    }

    return 0;
}