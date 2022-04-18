#include <math.h>
#include <stdio.h>

#define ROUNDS 5
#define ROOMS 4

#define ROOM1_SCORE 8.0f
#define ROOM2_SCORE 10.0f
#define ROOM3_SCORE 10.0f
#define ROOM4_SCORE 15.0f

void room1(int n_players, float players[n_players], int n_room, int room[n_room]) {
    float split_score = ROOM1_SCORE / n_room;

    int player_index = 0;
    while (player_index < n_room) {
        players[room[player_index]] += split_score;
        player_index++;
    }
}

void room2(int n_players, float players[n_players], int n_room, int room[n_room]) {
    if (n_room < 3) {
        return;
    }

    // Calculate sum
    float total_points = 0.0f;

    int room_index = 0;
    while (room_index < n_room) {
        total_points += players[room[room_index]];
        room_index++;
    }

    room_index = 0;
    while (room_index < n_room) {
        float ratio = players[room[room_index]] / total_points;
        players[room[room_index]] += ROOM2_SCORE * ratio;
    }
}

void room3(int n_players, float players[n_players], int n_room, int room[n_room]) {
    if (n_room > 4) {
        return;
    }

    float split_score = ROOM3_SCORE / n_room;

    int room_index = 0;
    while (room_index < n_room) {
        players[room[room_index]] += split_score + n_room;
        room_index++;
    }
}

int is_prime(int n) {
    int dividend = 2;

    while (dividend < n) {
        if (n % dividend == 0) {
            return 0;
        }

        dividend++;
    }

    return 1;
}

int two_same(int n_room, int room[n_room]) {
    int left = 0;

    while (left < n_room - 1) {
        int right = left + 1;

        while (right < n_room) {
            if (room[left] == room[right]) {
                return 1;
            }

            right++;
        }

        left++;
    }

    return 0;
}

int biggest_index(int n, float list[n]) {
    int biggest = 0;

    int index = 1;
    while (index < n) {
        if (list[index] > list[biggest]) {
            biggest = index;
        }

        index++;
    }

    return biggest;
}

void room4(int n_players, float players[n_players], int n_room, int room[n_room]) {
    if (is_prime(n_room) || two_same(n_room, room)) {
        return;
    }

    float split_score = ROOM4_SCORE / n_room;
    float player_points[n_room];

    int player_index = 0;
    while (player_index < n_room) {
        player_points[player_index] = players[room[player_index]];
        players[room[player_index]] += split_score;
        player_index++;
    }

    // Add extra points
    int extra_points = 5;
    while (extra_points > (5 - n_room) && extra_points > 0) {
        int index = biggest_index(n_room, player_points);

        players[room[index]] += extra_points;
        player_points[index] = -1;

        extra_points--;
    }
}

void process_round(int n_players, float players[n_players]) {
    int room_index = 0;
    while (room_index < ROOMS) {
        int n_players_in_room;
        scanf("%d\n", &n_players_in_room);

        int players_in_room[n_players_in_room];

        int player_index = 0;
        while (player_index < n_players_in_room) {
            int player;
            scanf("%d", &player);

            players_in_room[player_index] = player;

            getchar();
            player_index++;
        }

        if (room_index == 0) {
            room1(n_players, players, n_players_in_room, players_in_room);
        } else if (room_index == 1) {
            room2(n_players, players, n_players_in_room, players_in_room);
        } else if (room_index == 2) {
            room3(n_players, players, n_players_in_room, players_in_room);
        } else {
            room4(n_players, players, n_players_in_room, players_in_room);
        }

        room_index++;
    }
}

int main(void) {
    int n_players;
    scanf("%d\n", &n_players);

    float players[n_players];

    int round_index = 0;
    while (round_index < ROUNDS) {
        process_round(n_players, players);
        round_index++;
    }

    int player_index = 0;
    while (player_index < n_players) {
        printf("%.1f\n", players[player_index]);
        player_index++;
    }

    return 0;
}
