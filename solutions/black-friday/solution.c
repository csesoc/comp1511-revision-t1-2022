#include <stdio.h>
#include <stdlib.h>

void swap(int *num, int *num2)
{
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}

void bubbleSort(int a[], int lo, int hi)
{
   int i, j, nswaps;
   for (i = lo; i < hi; i++) {
      nswaps = 0;
      for (j = hi; j > i; j--) {
         if (a[j] < a[j-1]) {
            swap(&a[j], &a[j-1]);
            nswaps++;
         }
      }
      if (nswaps == 0) break;
   }
}


int main(void) {
    int *lesser, *greater;
    int integer1, integer2, lesser_index, greater_index;

    // Getting the Inputs.
    scanf("%d %d", &integer1, &integer2);
    int row1[integer1];
    int row2[integer2];
    for (int i = 0; i < integer1; i++) {
        scanf("%d", &row1[i]);
    }
    for (int i = 0; i < integer2; i++) {
        scanf("%d", &row2[i]);
    }


    if (integer1 < integer2) {
        lesser = row1;
        greater = row2;
        lesser_index = integer1;
        greater_index = integer2;
    } else {
        lesser = row2;
        greater = row1;
        lesser_index = integer2;
        greater_index = integer1;
    }

    bubbleSort(greater, 0, greater_index - 1);

    int sum = 0;
    for (int i = 0; i < lesser_index; i++) {
        sum += lesser[i];
    }
    for (int i = greater_index - lesser_index; i < greater_index; i++) {
        sum += greater[i];
    }

    printf("%d\n", sum);
    return 0;
}
