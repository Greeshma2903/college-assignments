// Write a program to demonstrate function returning pointers
#include <stdio.h>

int *calcSum(int a, int b, int *sum);

int main()
{
    int sum, a, b, *ptrSum;
    printf("\nEnter two integers:");
    scanf("%d %d", &a, &b);

    // function call (received by pointer)
    ptrSum = calcSum(a, b, &sum);
    printf("\nThe sum of the two numbers is %d", *ptrSum);

    return 0;
}

// return type is pointer
int *calcSum(int a, int b, int *sum)
{
    *sum = a + b;
    return sum;
}
