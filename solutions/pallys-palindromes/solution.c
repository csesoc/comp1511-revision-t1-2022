#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX 4096

int main(void) {
    char str[MAX];
    fgets(str, MAX, stdin);

    int len = strlen(str);

    // remove new line character from input string
    str[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != tolower(str[len-i-1])) {
            printf("String is not a palindrome\n");
            // early return if not a palindrome
            return 0;
        }
    }

    printf("String is a palindrome\n");
    return 0;
}
