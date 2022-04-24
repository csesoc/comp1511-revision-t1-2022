#include <stdio.h>
#include <stdlib.h>

#define GOOD 0
#define ERROR 1

struct stack_node {
    int bracket;
    struct stack_node *next;
};

struct stack {
    struct stack_node *head;
};

// function to check if the top of stack matches the closing bracket
int check_stack (struct stack *brackets, int bracket);

int main(void) {

    struct stack *brackets = malloc(sizeof(struct stack));
    brackets->head = NULL;

    int next_bracket;
    while ((next_bracket = getchar()) != '\n' && next_bracket != EOF) {
        if (next_bracket == '(' || next_bracket == '{' || next_bracket == '[') {
            struct stack_node *curr = malloc(sizeof(struct stack_node));
            curr->bracket = next_bracket;
            curr->next = brackets->head;
            brackets->head = curr;
            
        } else if (next_bracket == ')') {
            if (check_stack(brackets, '(') == ERROR) {
                printf("No, not balanced\n");
                return 0;
            }

        } else if (next_bracket == ']') {
            if (check_stack(brackets, '[') == ERROR) {
                printf("No, not balanced\n");
                return 0;
            }

        } else if (next_bracket == '}') {
            if (check_stack(brackets, '{') == ERROR) {
                printf("No, not balanced\n");
                return 0;
            }
        }
    }

    if (brackets->head != NULL) {
        printf("No, not balanced\n");
        return 0;
    }

    printf("Yes, balanced\n");
    return 0;
}

int check_stack (struct stack *brackets, int bracket) {
    if (brackets->head != NULL && brackets->head->bracket == bracket) {
        struct stack_node *prev = brackets->head;
        brackets->head = brackets->head->next;
        free(prev);
        return GOOD;
    }
    return ERROR;
}
