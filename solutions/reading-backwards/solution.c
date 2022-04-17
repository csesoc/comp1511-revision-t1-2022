#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1024

int main() {
    char str[MAX + 1];
    fgets(str, MAX, stdin);

    int len = strlen(str);

    int temp;
    for (int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp; 
    }
    
    printf("%s\n", str);
    
    return 0;
}
