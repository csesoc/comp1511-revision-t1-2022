#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX 4096

int main(void) {
    char str[MAX];
    fgets(str, MAX, stdin);

    int len = strlen(str);

    int i = 0;

    // Keep comparing characters while their mirrored position is the same
    while (i < len) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            printf("String is not a palindrome\n");
            // early return if not a palindrome
            return 0;
        }
        i++;
    }

    // Otherwise, it must be a palindrome
    printf("String is a palindrome\n");
    return 0;
}
