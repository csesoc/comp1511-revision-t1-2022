#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isVowel(char a);

int main (void) {
    char w[1024];
    char lb[1024];
    char buf[10];
    int n;

    fgets(buf, 1024, stdin);
    n = atoi(buf);
    fgets(w, 1024, stdin);
    fgets(lb, 1024, stdin);

    int v = 0;
    // Find index of vowels
    for (int i = 0; i < n; i++)
        if (w[i] != '-') v = (isVowel(w[i])) ? i % 2 : (i + 1) % 2;

    // Replace each item with its max
    int cCount = 0;
    int vCount = 0;
    int counts[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (w[i] != '-') continue;
        int searchInd = i % 2 == v;

        for (int j = counts[searchInd]; j < n; j++)
        {
            if ((searchInd && isVowel(lb[j])) || (!searchInd && !isVowel(lb[j])))
            {
                w[i] = lb[j];
                counts[searchInd] = j+1;
                break;
            }
        }
        if (w[i] == '-') {
            printf("Cannot be done!\n");
            exit(0);
        }
    }
    int final = 0;

    for (int i = 0; i < n; i++)
        final += w[i] - 'a' + 1;
    printf("%d\n", final);

}

bool isVowel(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? true : false;
}

