// Selection Sort
#include<stdio.h>
#define MAX 100
int main()
{
	int a[MAX], i, j, n, temp, minIndex;
	printf("\nEnter the size of list:  ");
	scanf("%d", &n);
    // Read elements
	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:  ",i+1);
		scanf("%d", &a[i]);
	}
    // Sort list
	for(i = 0; i<n-1; i++)
	{
		minIndex = i;
		for(j=i+1; j<n; j++)
		{
			if(a[j] < a[minIndex])
				minIndex = j;
		}
		if(i != minIndex)
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}
    // Print list
	printf("Sorted List is : \n");
	for(i = 0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
    return 0;
}