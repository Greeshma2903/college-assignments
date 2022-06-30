// C Program for Bellman Ford Algorithm (Dynamic Programming)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge
{
    /* Edges are directed edges so they contain 
    source and destination and cost.*/
    int source, destination, cost;
};

/* Represents a connected, directed and costed graph */
struct Graph
{
    int V, E;

    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->V = V; 
    graph->E = E;

    /* Creating "Edge" structures inside "Graph" structure, 
    the number of edge type structures are equal to number of edges */
    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

void FinalSolution(int dist[], int n)
{
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;

    for (i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void BellmanFord(struct Graph *graph, int source)
{
    int V = graph->V;

    int E = graph->E;

    int StoreDistance[V];

    int i, j;

    /* Initialize all distances excpet source as INF. 
    Source is set at 0. */
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;

    StoreDistance[source] = 0;

    /* Perform V-1 Relaxation Steps */
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;

            int v = graph->edge[j].destination;

            int cost = graph->edge[j].cost;

            if (StoreDistance[u] + cost < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + cost;
        }
    }

    /* Check if we get a shorter path, then there is a negative edge cycle. */
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;

        int v = graph->edge[i].destination;

        int cost = graph->edge[i].cost;

        if (StoreDistance[u] + cost < StoreDistance[v])
        {
            printf("This graph contains negative edge cycle, hence Algorithm cannot be applied.\n");
            return;
        }
    }

    /* Print Solution */
    FinalSolution(StoreDistance, V);

    return;
}

int main()
{
    int V, E, S;

    printf("Enter number of vertices in graph: ");
    scanf("%d", &V);

    printf("Enter number of edges in graph: ");
    scanf("%d", &E);

    // Read Source vertex from user
    printf("Enter your source vertex number: ");
    scanf("%d", &S);

    /* Create Graph based on User Input */
    struct Graph *graph = createGraph(V, E); 
    
    /* Read Graph Values */
    printf("\n");
    int i;
    for (i = 0; i < E; i++)
    {
        printf("\nEnter edge %d properties (Source, destination, Cost): ", i + 1);
        scanf("%d", &graph->edge[i].source);
        scanf("%d", &graph->edge[i].destination);
        scanf("%d", &graph->edge[i].cost);
    }

    // BellmanFord Algorithm function (graph, source vertex passed)
    BellmanFord(graph, S);

    return 0;
}