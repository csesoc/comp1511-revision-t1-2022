#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// This file describes the interface to a stack of ints
// These Stack helper functions may be seen in lecture code.

// ======================================================
// The type "Stack" refers to a stack_internals pointer.
// In other files, programs can use Stack, but they will
// not get direct access to the stack's internal workings
// nor will they know exactly what they are
typedef struct stack_internals *Stack;

// ======================================================
// These functions are the only way external code can
// manipulate a stack.

// functions to create and destroy stacks
Stack stack_create(void);
void stack_free(Stack s);

// Add and remove items from stacks
// Removing the item returns the item for use
void stack_push(Stack s, int item);
int stack_pop(Stack s);

// Check on the size of the stack
int stack_size(Stack s);

// Stack internals holds a pointer to the start of a linked list
struct stack_internals {
 struct stack_node *head;
 int size;
};

struct stack_node {
 struct stack_node *next;
 int data;
};

void stack_free(Stack s);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int curr_bracket;
    int popped_bracket;
    Stack bracketStack = stack_create();

    curr_bracket = getchar();

    while (curr_bracket != EOF) {
        if (curr_bracket == '{' || curr_bracket == '[' || curr_bracket == '(') {
            stack_push(bracketStack, curr_bracket);
        } else if (curr_bracket == '}' || curr_bracket == ']' || curr_bracket == ')') {
            if (stack_size(bracketStack) == 0) {
                printf("No, not balanced");
                stack_free(bracketStack);
                return 0;
            }
            popped_bracket = stack_pop(bracketStack);
            if ((curr_bracket == '}' && popped_bracket != '{') ||
                (curr_bracket == ')' && popped_bracket != '(') ||
                (curr_bracket == ']' && popped_bracket != '[')) {
                printf("No, not balanced");
                stack_free(bracketStack);
                return 0;                 
            }
        }
        curr_bracket = getchar();
    }

    if (stack_size(bracketStack) == 0) {
        printf("Yes, balanced");
    } else {
        printf("No, not balanced");
    }

    stack_free(bracketStack);

    return 0;
}


void stack_free(Stack s) {
    struct stack_node *curr = s->head;
    while (curr != NULL) {
        struct stack_node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(s);
}

// Create an empty Stack
Stack stack_create(void) {
    Stack new_stack = malloc(sizeof(struct stack_internals));
    new_stack->head = NULL;
    new_stack->size = 0;
    return new_stack;
}

void stack_push(Stack s, int item) {
    s->size++;
    struct stack_node *new_node = malloc(sizeof(struct stack_node));
    new_node->data = item;

    // Attach new_node to the old head and make it the new head
    new_node->next = s->head;
    s->head = new_node;
}

// Remove the head from the list and free the memory used
int stack_pop(Stack s) {
    s->size--;
    // This is error handling if the stack was NULL:
    //  if (s->head == NULL) {
    //  printf("Attempt to pop an element from an empty stack.\n");
    //  exit(1);
    //  }

    // For us, assume that there is never an empty stack.
    // Read the value from the head
    int return_data = s->head->data;
    struct stack_node *remNode = s->head;

    // move the stack head to the new head and free the old
    s->head = s->head->next;
    free(remNode);

    return return_data;
}

int stack_size(Stack s) {
    return s->size;
}