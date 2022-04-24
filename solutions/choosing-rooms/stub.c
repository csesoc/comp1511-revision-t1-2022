#include <stdio.h>

#define ROUNDS 5
#define ROOMS  4

#define ROOM1_SCORE 8.0f
#define ROOM2_SCORE 10.0f
#define ROOM3_SCORE 10.0f
#define ROOM4_SCORE 15.0f

// HELPER CODE

struct room {
    // number of players in this room
    int n_players;
    // players_in_room is an array of size `players` containing all players that
    // entered this room, exactly as inputted - if n_players is 0,
    // this is a NULL pointer
    int *players_in_room;
};

struct room get_room_details() {
    int n_players;
    scanf("%d\n", &n_players);

    struct room room_data;

    if (n_players == 0) {
        room_data.n_players = 0;
        room_data.players_in_room = NULL;
    } else {
        int players_in_room[n_players];

        int p_index = 0;

        while (p_index < n_players) {
            int current_player;
            scanf("%d ", &current_player);

            players_in_room[p_index] = current_player;

            p_index++;
        }

        room_data.n_players = n_players;
        room_data.players_in_room = players_in_room;
    }

    return room_data;
}

// WRITE YOUR CODE HERE

int main(void) {
    // Get number of players
    int n_players;
    scanf("%d\n", &n_players);

    // Parse input
    int round = 0;

    while (round < ROUNDS) {
        int room = 0;

        while (room < ROOMS) {
            struct room room_details = get_room_details();

            // Do something with each room

            room++;
        }

        round++;
    }

    // Print output
}
