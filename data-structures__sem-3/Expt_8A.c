#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int adjacency_matrix[MAX][MAX];
int n,type_of_graph;
void create_graph();
void display();
void insert_edge(int, int);
void del_edge(int, int);
void insert_vertex();
void del_vertex();
int main()
{	
	int choice,ori,dest;
	
	create_graph();
	printf("\n----------------------------------\n");
	
	while(1)
	{
		printf("1. Insert a vertex\n");
		printf("2. Insert an edge\n");
		printf("3. Delete a vertex\n");
		printf("4. Delete a edge\n");
		printf("5. Display a graph\n");
		printf("6. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_vertex();
					printf("\n----------------------------------\n");
					break;
			
			case 2: printf("Enter the edge to be inserted:");
					scanf("%d%d",&ori,&dest);
					insert_edge(ori,dest);
					printf("\n----------------------------------\n");
					break;
					
			case 3: del_vertex();
					printf("\n----------------------------------\n");
					break;
					
			case 4: printf("Enter the edge to be deleted:");
					scanf("%d%d",&ori,&dest);
					del_edge(ori,dest);
					printf("\n----------------------------------\n");
					break;
			
			case 5: display();
					printf("\n----------------------------------\n");
					break;
			
			case 6: return 0;
			default: printf("Invalid choice");
		}
	}
	return 0;
}
void display()
{
	int i,j;
	
	printf("The elements in the adjacency matrix are:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d	",adjacency_matrix[i][j]);
		}
		if (i!=n-1)
			printf("\n");
	}
}
void create_graph()
{
	int max_edges,i,j,origin,dest;
	
	printf("Enter:\n");
	printf("1. Directed Graph\n");
	printf("2. Undirected Graph\n");
	scanf("%d",&type_of_graph);
	
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	
	if (type_of_graph == 1)
		max_edges = n*(n-1);
	
	else
		max_edges = (n*(n-1))/2;
		
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(-1,-1 to exit):",i);
		scanf("%d%d",&origin,&dest);
		
		if (origin == -1 && dest == -1)
			break;
		
		else if (origin >= n || dest >= n || dest < 0 || origin < 0)
		{
			printf("Invalid vertex\n");
			i--;
		}
		else
		{
			adjacency_matrix[origin][dest] = 1;
			if (type_of_graph == 2)
				adjacency_matrix[dest][origin] = 1;	
		}
	}
}
void insert_edge(int origin, int dest)
{
	if (origin >= n || origin < 0)
	{
		printf("Origin vertex does not exist\n");
		return;
	}
	else if (dest >= n || dest < 0)
	{
		printf("Destination vertex does not exist\n");
		return;
	}
	else 
	{
		adjacency_matrix[origin][dest] = 1;
		if (type_of_graph == 2)
			adjacency_matrix[dest][origin] = 1;	
	}
		
}
void del_edge(int origin, int dest)
{
	if (origin >= n || origin < 0)
	{
		printf("Origin vertex does not exist\n");
	}
	else if (dest >= n || dest < 0)
	{
		printf("Destination vertex does not exist\n");
	}
	else if (adjacency_matrix[origin][dest] == 0)
	{
		printf("Invalid vertex\n");
	}
	else 
	{
		adjacency_matrix[origin][dest] = 0;
		if (type_of_graph == 2)
			adjacency_matrix[dest][origin] = 0;	
	}
		
}
void insert_vertex()
{
	int i,origin,dest,max = n;
	n++;
	
	if (type_of_graph == 2)
	{
		for(i=1;i<=max;i++)
		{
			printf("Enter edge %d's destination(-1 to exit):",i);
			scanf("%d",&dest);
			if (dest == -1)
				break;
			
			else if (dest >= n || dest < 0)
			{
				printf("Invalid vertex\n");
				i--;
			}
			else
				insert_edge(max,dest);
		}
	}
	else
	{
		int origin;
		for(i=1;i<=max;i++)
		{
			
			printf("Enter edge %d(-1,-1) to exit):",i);
			scanf("%d%d",&origin,&dest);
			if (dest == -1 && origin == -1)
				break;
			
			else if (dest >= n || dest < 0 || origin >= n || origin < 0)
			{
				printf("Invalid vertex\n");
				i--;
			}
			else if (origin == max || dest == max)
				insert_edge(origin,dest);
			
			else
				printf("Invalid vertex is being inserted\n");
		}
	}
}
void del_vertex()
{
	int i,vertex;
		
	printf("Enter the vertex to be deleted:");
	scanf("%d",&vertex);
	
	if (vertex > n)
	{
		printf("Invalid vertex\n");
		return;
	}
	
	while(vertex < n)
	{
		for(i=0;i<n;i++)			//Shifting the rows to left
			adjacency_matrix[i][vertex] = adjacency_matrix[i][vertex+1];
			
		for(i=0;i<n;i++)			//Shifting the columns up
			adjacency_matrix[vertex][i] = adjacency_matrix[vertex+1][i];	
		
		vertex++;
	}
	n--;
}
