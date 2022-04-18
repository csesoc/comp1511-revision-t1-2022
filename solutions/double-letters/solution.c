#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 0;

    int c;
    int prev = -1;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c == prev) {
            // if current letter is same as previous, increase counter
            count++;
        }
        prev = c;
    }
    printf("%d\n", count);
    return 0;
}
