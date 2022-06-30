#include<stdio.h>
void MaxMin(int a[], int i, int j, int *max, int *min);
int main()
{
	int n, i, j, max, min;
	
	printf("\nEnter size of array:");
	scanf("%d", &n);
	int a[n];
	
	// read array values
	printf("\nEnter array elements: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	// initialize min and max
	min = a[0];
	max = a[0];
	
	// make recursive call
	MaxMin(a, 0, n-1, &min, &max);
	printf("\n Max: %d\n Min: %d", max, min);
	return 0;
}

void MaxMin(int a[], int i, int j, int *max, int *min)
{
	int min1, max1, mid;
	if(i == j) 
	{	
		*min = a[i];
		*max = a[i];
	}
	else if(i == j -1)
	{
		if(a[i] < a[j])
		{
			*min = a[i];
			*max = a[j];
		}
		else {
			*min = a[j];
			*max = a[i];
		}
	}
	else {
		int mid = (i + j)/2;
		// first recursive call
		MaxMin(a, i, mid, max, min);
		
		min1 = *min;
		max1 = *max;
		// second recursive call
		MaxMin(a, mid+1, j, &max1, &min1);
		
		if(*max < max1) *max = max1;
		if(*min > min1) *min = min1;
	}
}
