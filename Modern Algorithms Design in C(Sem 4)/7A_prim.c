#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Maximum Number of vertices in the graph
#define MAX_VERTEX 15

int graph[MAX_VERTEX][MAX_VERTEX];
int V;
int stepcount = 0;

int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	int v;
	for (v = 0; v < V; v++)
	{										stepcount++;
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
											stepcount++;
	}										stepcount++;

	return min_index;
}

// print the constructed MST stored in parent[]
void printMST(int parent[])
{
	int i, j, minCost = 0;
	printf("\nThe minimum cost spanning tree will be: \n");
	printf("\nEdge \tWeight\n");				stepcount++;
	for (i = 1; i < V; i++)
	{										stepcount++;
		printf("%2d - %2d%4d \n", parent[i], i, graph[i][parent[i]]);
		minCost += graph[i][parent[i]];		stepcount++;
	}										stepcount++;
	printf("\n=> Minimum cost = %d", minCost);
}

void primMST()
{
	int i, count, v;

	int parent[V];
	int key[V];
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (i = 0; i < V; i++){
		key[i] = INT_MAX, mstSet[i] = false;	stepcount++;
	}											stepcount++;

	key[0] = 0;									
	parent[0] = -1; // First node is always root of MST

	// The MST will have V-1 Edges
	for (count = 0; count < V - 1; count++)
	{											stepcount++;
		// pick min key vertex not yet included in MST
		int u = minKey(key, mstSet);			stepcount++;

		// Add the picked vertex to the MST Set
		mstSet[u] = true;						stepcount++;

		for (v = 0; v < V; v++)
		{										stepcount++;
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];	
												stepcount++;
		}
	}											stepcount+=2;
	printMST(parent);					stepcount++;
}

int main()
{

	int i, j;								
	printf("\nEnter the number of vertices:");
	scanf("%d", &V);						stepcount++;

	printf("\nEnter the costs of vertices:(matrix form)");
	for (i = 0; i < V; i++)					
	{										stepcount++;
		for (j = 0; j < V; j++)				
		{									stepcount++;
			scanf("%d", &graph[i][j]);		stepcount++;
		}
	}										stepcount+=2;

	// Print the solution
	primMST();							stepcount++;
	
	printf("\n\nStep count: %d", stepcount);

	return 0;
}
