#include <stdio.h>
#include <stdlib.h>

void swap(int *num, int *num2);
void bubbleSort(int a[], int lo, int hi);
void sort(int array[], int newer[], int size);

int main(void)
{
    // Integer pointers, you can point them to an integer array.
    int *smaller_array, *larger_array;
    int bob_item_count, sue_item_count, smaller_array_size, larger_array_size;

    // Getting the inputs into the array.
    scanf("%d %d", &bob_item_count, &sue_item_count);
    int bob[bob_item_count];
    int sue[sue_item_count];
    int counter = 0;
    while (counter < bob_item_count)
    {
        scanf("%d", &bob[counter]);
        counter++;
    }
    counter = 0;
    while (counter < sue_item_count)
    {
        scanf("%d", &sue[counter]);
        counter++;
    }

    // Figuring out which of the two array is the smaller one.
    if (bob_item_count < sue_item_count)
    {
        smaller_array = bob;
        larger_array = sue;
        smaller_array_size = bob_item_count;
        larger_array_size = sue_item_count;
    }
    else
    {
        smaller_array = sue;
        larger_array = bob;
        smaller_array_size = sue_item_count;
        larger_array_size = bob_item_count;
    }

    // Summing up the items in the smaller_array.
    int total_price = 0;
    counter = 0;
    while (counter < smaller_array_size)
    {
        total_price += smaller_array[counter];
        counter++;
    }

    /*
        Getting the N most expensive items from the larger array
    */
    // method 1: lopping through the larger array `N` times, find the largest element, add it to `total_price`, and replace that element with -1.
    counter = 0;
    while (counter < smaller_array_size)
    {
        int curr_max = -1;
        int max_index = -1;
        int index = 0;
        while (index < larger_array_size)
        {
            if (larger_array[index] > curr_max)
            {
                curr_max = larger_array[index];
                max_index = index;
            }
            index++;
        }
        larger_array[max_index] = -1;
        total_price += curr_max;
        counter++;
    }

    // method 2: Sort the larger_array, and grab the items from there.
    /*
    bubbleSort(larger_array, 0, larger_array_size - 1);
    counter = larger_array_size - smaller_array_size;
    while (counter < larger_array_size) {
        total_price += larger_array[counter];
    }
    */

    // print out the total_price.
    printf("%d\n", total_price);
    return 0;
}

/*
    Simple sorting algorithm,
    Given an array of size N.
    make multiple passes from index N-1 to i (where i is equal to 0...N-1).
    on each pass, swap any out of order adjacent pairs.
    eventually, the smallest element will be moved to the ith position.
    repeat until all elements are moved to the appropiate position.
*/
void bubbleSort(int a[], int lo, int hi)
{
    int i, j, nswaps;
    i = lo;
    while (i < hi)
    {
        nswaps = 0;
        j = hi;
        while (j > i)
        {
            if (a[j] < a[j - 1])
            {
                swap(&a[j], &a[j - 1]);
                nswaps++;
            }
            j--;
        }
        if (nswaps == 0)
        {
            break;
        }
        i++;
    }
}

/*
    This function swaps two array elements.
*/
void swap(int *num, int *num2)
{
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}