/*
Write a function that receives marks received by a student in 3 subjects and
returns the average and percentage of these marks. Call this function from main( )
and print the results in main( ).
*/

#include <stdio.h>

void calcAvg(float *avg, float *percent)
{
    float mark1, mark2, mark3;

    // Read marks
    printf("Enter marks in 3 subject:");
    printf("\nSubject 1:");
    scanf("%f", &mark1);

    printf("\nSubject 2:");
    scanf("%f", &mark2);

    printf("\nSubject 3:");
    scanf("%f", &mark3);

    // Calculate average
    *avg = (mark1 + mark2 + mark3) / 3;
    *percent = ((mark1 + mark2 + mark3)/300)* 100;
}

int main()
{
    float avg, percent;

    // Function call
    calcAvg(&avg, &percent);

    // Display averaga
    printf("The average marks scored by student is %0.2f", avg);
    printf("\nPercentage: %0.2f%%", percent);

    return 0;
}
