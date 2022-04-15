#include <stdio.h>

#define MAX_LENGTH 1000

void solve(int length, char *input) {
    int references = 0;

    for (int index = length - 1; index >= 0; index--) {
        char current = input[index];

        if (current == '&') {
            references--;
        } else if (current == '*') {
            references++;
        }

        if (references < 0) {
            printf("not possible\n");
            return;
        }
    }

    for (int count = 0; count < references; count++) {
        printf("pointer to ");
    }

    printf("c\n");
}

int main(void) {
    int length;
    char input[MAX_LENGTH];

    scanf("%d", &length);
    scanf("%1000s", input);

    solve(length, input);

    return 0;
}
