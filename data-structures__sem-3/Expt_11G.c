// Radix sort

#include<stdio.h>
#include<stdlib.h>

struct  node
{
	int data ;
	struct node *link;
}*start=NULL;

int digit(int number, int k)
{
	int digit, i ;
	for(i=1; i<=k; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
    // Returns the kth digit of number
	return(digit);
}

int large_dig()
{
	struct node *p=start;
	int large=0,ndig=0;

	// Find Largest element
	while(p != NULL)
	{
		if(p ->data > large)
			large = p->data;
		p = p->link ;
	}
	// Num of digits in largest number
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}
	return(ndig);
}

// Radix sort
void radix_sort()
{
	int i,k,dig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];

	least_sig=1;
	most_sig=large_dig(start);

	for(k=least_sig; k<=most_sig; k++)
	{
		// Empty the queues initially
		for(i=0; i<=9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL ;
		}

		for( p=start; p!=NULL; p=p->link )
		{
			dig = digit(p->data, k);

			if(front[dig] == NULL)
				front[dig] = p ;
			else
				rear[dig]->link = p;
			rear[dig] = p;
		}

		// Join all queues
		i=0;
		while(front[i] == NULL)
			i++;
		start = front[i];
		while(i<9)
		{
			if(rear[i+1]!=NULL)
				rear[i]->link=front[i+1];
			else
				rear[i+1]=rear[i];
			i++;
		}
		rear[9]->link=NULL;
	}
}

// Main function ----------------------------------------------------------------
int main()
{
	struct node *tmp,*q;
	int i,n,item;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&item);

        // Linked list insertion
		tmp= malloc(sizeof(struct node));
		tmp->data=item;
		tmp->link=NULL;

		if(start==NULL)
			start=tmp;
		else
		{
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}

	radix_sort();
	printf("Sorted list is :\n");

	q=start;
	while( q !=NULL)
	{
		printf("%d ", q->data);
		q = q->link;
	}
	printf("\n");
    return 0;
}

