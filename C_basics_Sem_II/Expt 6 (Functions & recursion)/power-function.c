// Write a function power ( a, b ), to calculate the value of a raised to b.
#include <stdio.h>

int main()
{
    void powerOf(int a, int b); // Function decalaration

    int a, b;
    printf("Enter a integer and its power:");
    scanf("%d %d", &a, &b);

    // function Call
    powerOf(a, b);

    return 0;
}

// Function definition
void powerOf(int a, int b) // parameters list
{
    int value = 1, i;
    
    for(i= 0; i < b; i++)
        value *= a;

    printf("\n %d raised to %d = %d", a, b, value);
}
