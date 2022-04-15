#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 101

struct Node {
    char *name;
	struct Node *next;
};

typedef struct Node *Students;

Students insertStudent(char *name, Students l);

/**
 * stores marks into an array
 * inserts names alphabeticlay into a linked list
 * prints the marks and names together
 */
int main(void) {
    int total;
    scanf("%d", &total);

    int markStore[total];
    for (int i = 0; i < total; i++) {
        scanf("%d ", &markStore[i]);
    }

    Students studentInfo = NULL;
    for (int i = 0; i < total; i++) {
        char studentName[MAX_LEN];
        scanf("%s", studentName);
        studentInfo = insertStudent(studentName, studentInfo);
    }

    Students curr = studentInfo;
    int j = 0;
    while (curr != NULL) {
        printf("%s %d\n", curr->name, markStore[j]);
        j++;
        curr = curr->next;
    }
}

/**
 * inserts student name in alaphbetical order into a linked list
 */
Students insertStudent(char *name, Students l) {
    if (l == NULL || strcmp(l->name, name) > 0) {
        Students new = malloc(sizeof(*new));
        new->name = (char*) malloc((MAX_LEN)*sizeof(char));
        strcpy(new->name, name);
        new->next = l;
        return new;
    }

    l->next = insertStudent(name, l->next);
    return l;
}