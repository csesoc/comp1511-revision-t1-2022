#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_STRING_LEN 105
#define MAX_DAYS 1005

// We're making two linked lists in one struct here.

// The 'track list' follows the track pointer - we use this
// to answer the query.

// The 'name list' follows the next pointer - we use this
// to search for a station given its name.
typedef struct Node {
    char name[MAX_STRING_LEN];
    struct Node *track;
    struct Node *next;
} Node;

struct Node *name_to_pointer(Node *head, char name[MAX_STRING_LEN]);
int can_reach_goal(Node *head, Node *goal);
void prune_newline(char str[MAX_STRING_LEN]);

int main(void) {
    Node *home = malloc(sizeof (Node));
    strcpy(home->name, "home");
    Node *unsw = malloc(sizeof (Node));
    strcpy(unsw->name, "unsw");
    home->next = unsw;
    home->track = unsw;
    unsw->next = NULL;
    unsw->track = NULL;

    // Keeping track of the end of the 'name list' for convenience.
    Node *name_end = unsw;

    int days;
    scanf("%d\n", &days);

    int counter = 0;
    char command;
    char name1[MAX_STRING_LEN];
    char name2[MAX_STRING_LEN];
    while (counter < days) {
        scanf("%c ", &command);
        if (command == 's') {
            fgets(name1, MAX_STRING_LEN, stdin);
            prune_newline(name1);           

            Node *new_node = malloc(sizeof (Node));
            strcpy(new_node->name, name1);
            new_node->next = NULL;
            new_node->track = NULL;

            name_end->next = new_node;
            name_end = new_node;
        } else if (command == 't') {
            fgets(name1, MAX_STRING_LEN, stdin);
            prune_newline(name1);
            fgets(name2, MAX_STRING_LEN, stdin);
            prune_newline(name2);

            Node *start_node = name_to_pointer(home, name1);
            Node *end_node = name_to_pointer(home, name2);
            start_node->track = end_node;
        }
        if (can_reach_goal(home, unsw) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        counter++;
    }

}

// Converts the name of a station to a pointer.
// Arguments: the head of the name list, the name of the station
// Returns: a pointer to the (first) station with the given name, or null
// 			if there is no matching station.
struct Node *name_to_pointer(Node *head, char name[MAX_STRING_LEN]) {
    Node *current = head;
    Node *result = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Checks whether it is possible to go between to nodes in the linked list.
// Arguments: the start and goal nodes
// Returns: 1 if it is possible to reach the goal, or 0 otherwise
int can_reach_goal(Node *head, Node *goal) {
    Node *current = head;
    int counter = 0;

    // Counter ensures we don't end up looping forever - we know there
    // can't be more stations than there are days, so after that many
    // moves, we must be in a loop.
    while (current != NULL && current != goal && counter < MAX_DAYS) {
        current = current->track;
        counter++;
    }
    
    if (current == goal) {
        return 1;
    } else {
        return 0;
    }
}

// Removes a terminal newline from a given string.
// Arguments: the string to be pruned
// Returns: nothing
void prune_newline(char str[MAX_STRING_LEN]) {
	if (str[strlen(str) - 1] == '\n') {
       	str[strlen(str) - 1] = '\0';
    }
}
