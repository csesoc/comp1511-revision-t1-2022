#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
    int n;
    scanf("%d", &n);

    int maxSum = -1;
    int groupNum = 0;

    for (int i = 0; i < n; i++) {
        int ki;
        scanf("%d", &ki);
        int thisTotal = 0;
        for (int j = 0; j < ki; j++) {
            int curr;
            scanf("%d", &curr);
            thisTotal += curr;
        }
        if (thisTotal > maxSum) {
            maxSum = thisTotal;
            groupNum = i + 1;
        }
    }

    printf("%d\n", groupNum);
}
