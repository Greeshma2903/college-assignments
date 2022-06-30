// C Program for All Pairs Shortest Path Algo (Floyd Warshell)
#include <stdio.h>
#define INF 99999

// Number of vertices in the graph
int V;

void printOutputMatrix(int dist[][V])
{
    printf("]nThe following matrix shows the shortest distances between all pairs: \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", dist[i][j]);
        }
        printf("\n");
    }
}

void AllPairsShortestPath(int graph[][V])
{
    /* Output matrix: has the shortest
    distances between every pair of vertices */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix
    same as input graph matrix. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Set of intermediate vertices. */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printOutputMatrix(dist);
}

// MAIN FUCNTION
int main()
{
    /* Read number of vertices */
    printf("\nEnter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V], i, j;

    /* Read Edges; For all non-diagonal elements that are zero
    equate them to INF (large) value */
    printf("\nEnter the cost of edges:(matrix form)");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    // Call Algo
    AllPairsShortestPath(graph);
    return 0;
}
