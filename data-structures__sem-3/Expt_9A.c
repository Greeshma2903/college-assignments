// LINEAR SEARCH
#include <stdio.h>
#define MAX 50

int LinearSearch(int arr[], int n, int ele)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == ele)
			return i;
	return -1;
}

// Main Function
int main()
{
	int arr[MAX], n, i, ele;
    printf("\nEnter the limit of array: ");
    scanf("%d", &n);
	for(i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n-------------------------\nEnter Element to be searched:");
    scanf("%d", &ele);
	int index = LinearSearch(arr, n, ele);
	if (index == -1)
		printf("\n=> Element is not present in the array");
	else
		printf("\n=> Element found at position %d", index);

	return 0;
}
