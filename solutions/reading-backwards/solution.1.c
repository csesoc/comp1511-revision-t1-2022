#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX_SIZE 1024

void reverse_function(char word[MAX_SIZE]);

int main (void) {
    char word[MAX_SIZE];
    printf("Input: ");
    fgets(word, MAX_SIZE, stdin);
    reverse_function(word);
    printf("Reversed input: %s", word);

    return 0;
}

void reverse_function(char word[MAX_SIZE]) {
    int i = 0;
    int holder;
    while (i < strlen(word)/2) {
        holder = word[i];
        word[i] = word[strlen(word) - 2 - i];
        word[strlen(word) - 2 - i] = holder;
        i++;
    }
}
