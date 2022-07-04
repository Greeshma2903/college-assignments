/*
Ten numbers are entered from the keyboard into an array. Write a
program to find out how many of them are positive, how many are
negative, how many are even and how many odd.
*/

#include <stdio.h>
#define size 10

int i;
// function declarations
void findPostiveNegative(int arr[]);
void findEvenOdd(int arr[]);

int main()
{
    int arr[size], i;

    // read list values
    printf("Enter a list of 10 integers:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // function calls
    findPostiveNegative(arr);
    findEvenOdd(arr);

    return 0;
}

// function to find positive and negative values in list
void findPostiveNegative(int arr[])
{
    int pos = 0;
    int neg = 0;

    for (i = 0; i < size; i++)	// if element > 0 --> positive, else negative
    {
        if (arr[i] >= 0)
            pos++;
        else
            neg++;
    }

    printf("\nThe number of positive values are: %d", pos);
    printf("\nThe number of negative values are: %d", neg);
}

// function to find the number of even and odd values in list
void findEvenOdd(int arr[])
{
    int even = 0;
    int odd = 0;

    for (i = 0; i < size; i++)	// if element divisible by 2 then odd, else even 
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("\nThe number of even values are: %d", even);
    printf("\nThe number of odd values are: %d", odd);
}

