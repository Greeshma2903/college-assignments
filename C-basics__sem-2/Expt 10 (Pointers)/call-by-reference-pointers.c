// Write a program using pointers to demonstrate call by reference in functions.
#include<stdio.h>
void swapValues(int *val1, int *val2);

int main()
{
    int a, b;

    printf("\nEnter two integers:");
    scanf("%d %d", &a, &b);

    printf("\nValues before swapping:-\na: %d \tb: %d", a, b);
    // function call (call by reference)
    swapValues(&a, &b);

    printf("\n\nValues after swapping:- \na: %d \tb: %d\n", a, b );

    return 0;
}

void swapValues(int *val1, int *val2)
{
    int temp;
    // changing the actual parameters itself
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}