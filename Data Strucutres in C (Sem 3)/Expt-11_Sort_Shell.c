// Shell Sort

#include<stdio.h>
#define MAX 100

int main()
{

	int arr[MAX],i,j,k,n,inc;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("\nEnter maximum increment (odd value) : ");
	scanf("%d",&inc);

	// Shell Sort
	while(inc>=1)
	{
		for(i=inc; i<n; i++)
		{
			k=arr[i];
			for(j=i-inc; j>=0 && k<arr[j]; j=j-inc)
				arr[j+inc]=arr[j];
			arr[j+inc]=k;
		}
		inc=inc-2; /*Decrease the increment*/
	}
    // Print list
	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

    return 0;
}

