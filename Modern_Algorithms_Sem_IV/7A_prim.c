#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	int v;
	for (v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// print the constructed MST stored in parent[]
int printMST(int parent[], int graph[V][V])
{
	int i, j;
	printf("Edge \tWeight\n");
	for (i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	int i, count, v;

	int parent[V];
	int key[V];
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V-1 Edges
	for (count = 0; count < V - 1; count++)
	{

		// pick min key vertex not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		for (v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}

int main()
{

	int n, i, j;
	printf("\nEnter the number of vertices:");
	scanf("%d", &n);

	int graph[n][n];

	printf("\nEnter the costs of vertices:(matrix form)");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	// Print the solution
	primMST(graph);

	return 0;
}
