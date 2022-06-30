#include<stdio.h>

void unsort(int index[], float x[], int n, float profit[], float weight[])
{
	int i,j,p;
	float temp;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(index[i] > index[j])
			{
				p = index[i];
				index[i] = index[j];
				index[j] = p;
				
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
				
				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;
			
				temp = profit[i];
				profit[i] = profit[j];
				profit[j] = temp;
			}
		}
}
void knapsack(int n,float w[], float profit[], float m, int index[])
{
	float x[20],tp = 0;
	int i,j,u;
	u = m;
	for(i=0;i<n;i++)
	x[i] = 0.0;
	for(i=0;i<n;i++)
	{
		if(w[i]>u)
			break;
		x[i] = 1.0;
		tp = tp + profit[i];
		u = u-w[i];
	}
	if(i<n)
		x[i] = u/w[i];
	tp = tp + (x[i] * profit[i]);
	
	unsort(index, x,n, profit, w);
	printf("The result vector is: ");
	for(i=0;i<n;i++)
	printf("%f ",x[i]);
	
	printf("\nThe total profit is: %f\n",tp);
}
int main()
{
	float weight[20], profit[20], m;
	int num,i,j,x;
	float ratio[20], temp;
	int index[20];
	printf("Enter the number of objects: ");
	scanf("%d",&num);
	printf("Enter the weights and profits of each object:\n");
	for(i=0;i<num;i++)
	{
		scanf("%f%f",&weight[i],&profit[i]);
		index[i] = i;
	}
	
	printf("Enter the capacity: ");
	scanf("%f",&m);
	do
	{
		printf("\n\nWhat do you want to do? 1:Max profit, 2: Min wt, 3: Decreasing order P/w, 4: Exit\n");
		scanf("%d",&x);
		switch(x)
		{
		case 1:
			//MAX PROFIT
			printf("For Max Profit\n");
			for(i=0;i<num;i++)
			{
				for(j=i+1;j<num;j++)
				{
					if(profit[i]<profit[j])
					{
						temp = weight[i];
						weight[i] = weight[j];
						weight[j] = temp;
			
						temp = profit[i];
						profit[i] = profit[j];
						profit[j] = temp;
						
						int p = index[i];
						index[i] = index[j];
						index[j] = p;
					}
				}
			}
			knapsack(num,weight,profit,m, index);
			break;
			
		case 2:
			//MIN WEIGHT
			printf("For min weight\n");
			for(i=0;i<num;i++)
			{
				for(j=i+1;j<num;j++)
				{
					if(weight[i]>weight[j])
					{
						temp = weight[i];
						weight[i] = weight[j];
						weight[j] = temp;
				
						temp = profit[i];
						profit[i] = profit[j];
						profit[j] = temp;
						
						int p = index[i];
						index[i] = index[j];
						index[j] = p;
					}
				}
			}
			knapsack(num,weight,profit,m, index);
			break;
	
		case 3:
			//P/W descending order
			printf("For Decreasing order of P/w\n");
			for(i=0;i<num;i++)
			ratio[i] = profit[i]/weight[i];
	
			for(i=0;i<num;i++)
			{
				for(j=i+1;j<num;j++)
				{
					if(ratio[i]<ratio[j])
					{
						temp = ratio[i];
						ratio[i] = ratio[j];
						ratio[j] = temp;
				
						temp = weight[i];
						weight[i] = weight[j];
						weight[j] = temp;
				
						temp = profit[i];
						profit[i] = profit[j];
						profit[j] = temp;
						
						int p = index[i];
						index[i] = index[j];
						index[j] = p;
					}
				}
			}
			knapsack(num,weight,profit,m,index);
			break;
		case 4:printf("EXIT\n");
			break;
		default:printf("Invalid\n");
			break;
		}
	}while(x!=4);
	return 0;
}
