/*
Question : Write a program to accept the values of x and y to 
calculate the carpeting required to cover Theresa's entire family room
*/

#include<stdio.h>

int main(){
    float x, y, area;
    printf("Enter the dimensions of the family room('x' ft by 'y' ft):");
    scanf("%f %f", &x, &y);

    // calculate area of family room
    area = x*y;
    printf("\nTheresa needs to buy a carpet of %f sq.ft. to cover the entire family room.", area);

    return 0;
}
