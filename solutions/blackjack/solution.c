#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of players
#define MAX_PLAYERS 5
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

        index++;
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

    if (value < 18 && size < 5) {
        return 0;
    }

    return 1;
}

int game_finished(int players, int hands[MAX_PLAYERS][MAX_CARDS]) {
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
    char *line = malloc(sizeof(char) * MAX_TITLE);

    fgets(line, MAX_TITLE, stdin);
    line[strlen(line) - 1] = '\0';

    return string_to_value(line);
}

int find_biggest(int players[MAX_PLAYERS]) {
    int biggest = 0;

    int index = 1;
    while (index < MAX_PLAYERS) {
        if (players[index] > players[biggest]) {
            biggest = index;
        }

        index++;
    }

    return biggest;
}

void display_hands(int players, int hands[MAX_PLAYERS][MAX_CARDS]) {
    int hand_values[MAX_PLAYERS] = {0};

    int index = 0;
    while (index < players) {
        int value = hand_value(hands[index]);

        if (value > 21) {
            value = 1;
        }

        hand_values[index] = value;
        index++;
    }

    int sorted[MAX_PLAYERS] = {0};

    index = 0;
    while (index < players) {
        int biggest = find_biggest(hand_values);
        sorted[index] = biggest;
        hand_values[biggest] = 0;
        index++;
    }

    index = 0;
    while (index < players) {
        int current = sorted[index];
        printf(
            "Player %d %s %s %s %s %s\n", current + 1,
            value_to_string(hands[current][0]), value_to_string(hands[current][1]),
            value_to_string(hands[current][2]), value_to_string(hands[current][3]),
            value_to_string(hands[current][4])
        );

        index++;
    }
}

int main(void) {
    int players;
    scanf("%d\n", &players);

    int hands[MAX_PLAYERS][MAX_CARDS] = { {0} };

    // Could be done with calloc(), but assuming 1511 knowledge here
    int index = 0;
    while (index < players) {
        int card_index = 0;
        while (card_index < 2) {
            int drawn = get_card();
            hands[index][card_index] = drawn;

            card_index++;
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
    display_hands(players, hands);

    return 0;
}
