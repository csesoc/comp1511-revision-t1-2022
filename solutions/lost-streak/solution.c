#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1024

void rearrange(char string[MAX_SIZE]);



int main(void) {
    char string[MAX_SIZE] = {0};
    fgets(string, MAX_SIZE, stdin);
    rearrange(string);
    printf("%s",string);
}

void rearrange(char string[MAX_SIZE]) {
    int i = 0;
    int j = 1;
    int holder;
    while (i < strlen(string)) {
        j = i + 1;
        while (j < strlen(string) - 1) {
            if (string[j] < string[i]) {
                holder = string[i];
                string[i] = string[j];
                string[j] = holder;
            }
            
            j++;
        }
        
        i++;
        
    }
    
}