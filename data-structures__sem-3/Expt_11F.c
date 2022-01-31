// Iterative Merge Sort 

#include<stdio.h>
#define MAX 100

void merge(int a[], int temp[],int lw1, int up1, int lw2, int up2 )
{
	int i=lw1;
	int j=lw2;
	int k=lw1;

	while(i<=up1 && j<=up2 )
	{
		if( a[i] <= a[j] )
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=up1)
		temp[k++]=a[i++];
	while(j<=up2)
		temp[k++]=a[j++];
}

void copy(int a[], int temp[], int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]=temp[i];
}

void merge_pass(int a[], int temp[], int size, int n)
{
	int i,lw1,up1,lw2,up2;
	lw1=0;
	while( lw1 + size < n )
	{
		up1 = lw1 + size-1;
		lw2 = lw1 + size;
		up2 = lw2 + size-1;
		if( up2 >= n )/*if length of last sublist is less than size*/
			up2 = n-1;
		merge(a,temp,lw1,up1,lw2,up2);
		lw1=up2+1;	/*Take next two sublists for merging*/
	}
	for(i=lw1;i<=n-1;i++)
		temp[i]=a[i];	/*If any sublist is left*/
	copy(a, temp, n);
}

void merge_sort(int a[], int n)
{
	int temp[MAX];
	int size=1;
	while(size<n)
	{
		merge_pass(a,temp,size,n);
		size=size*2;
	}
}

// Main Function`
int main( )
{
	int a[MAX],i,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	merge_sort(a, n);

	printf("Sorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", a[i]);
	printf("\n");
}
