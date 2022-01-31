// Write a program using pointers to find the range of a given integer array. Range is the difference between max and min value.
#include <stdio.h>
#define SIZE 100

void findRange(int *ptr, int arrSize);

int main()
{
    int arr[SIZE], i, n;

    // read array size & array
    printf("\nEnter the size of array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // function call to calculate range
    findRange(arr, n);

    return 0;
}

void findRange(int *ptr, int arrSize)
{
    int i;
    // assign initial values to min & max
    int max = *ptr;
    int min = *ptr;
    // print array
    printf("\nYour array:\t");
    for (i = 0; i < arrSize; i++)
        printf("%d, ", *(ptr + i));

    // calculate max value in array
    for (i = 0; i < arrSize; i++)
        if (*(ptr + i) >= max)
            max = *(ptr + i);
    // calculate min value in array
    for (i = 0; i < arrSize; i++)
        if (*(ptr + i) <= min)
            min = *(ptr + i);
    // calculate range
    int range = max - min;

    // print values
    printf("\nMax value: %d", max);
    printf("\nMin value: %d", min);
    printf("\nThe range of the array is: %d", range);
}