#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int V;

/* Function to find the vertex with minimum distance value, from
the set of vertices not yet included in shortest path tree */
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    /* Final Array */
    int dist[V];    

    /* sptSet[i] will be true if vertex 'i' is included in shortest
    path tree or shortest distance from src to i is finalized */
    bool sptSet[V]; 

    /* Initially all distances are INFINITE and stpSet[] as false */
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Source Vertex
    dist[src] = 0;

    /* Find shortest path for all vertices */
    for (int count = 0; count < V - 1; count++)
    {
        /* Pick the minimum distance vertex from 
        the set of vertices not yet picked. */
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Relaxation of adjacent vertices
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

// MAIN FUNCTION  =========>
int main()
{
    int i, j;

    // Read the number of vertices
    printf("\nEnter the number of vertices(< 9):");
    scanf("%d", &V);

    int graph[V][V];

    // Read the values of Graph
    printf("\nEnter the costs of vertices:(matrix form)");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Function call: Implement Dijkstra
    dijkstra(graph, 0);

    return 0;
}
