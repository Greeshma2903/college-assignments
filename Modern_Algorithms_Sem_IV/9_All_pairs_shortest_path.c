// C Program for All Pairs Shortest Path Algo (Floyd Warshell)
#include <stdio.h>
#define INF 99999
#define MAX 15
int stepcount = 0;
// Number of vertices in the graph
int V;
int graph[MAX][MAX];

void printOutputMatrix(int dist[][MAX])
{
    printf("\nThe following matrix shows the shortest distances between all pairs: \n");
    for (int i = 0; i < V; i++)
    {                                             stepcount++;
        for (int j = 0; j < V; j++)
        {                                         stepcount+=2;
            if (dist[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", dist[i][j]);
        }
        printf("\n");
    }                                             stepcount++;
}

void AllPairsShortestPath()
{
    /* Output matrix: has the shortest
    distances between every pair of vertices */
    int dist[MAX][MAX], i, j, k;

    /* Initialize the solution matrix
    same as input graph matrix. */
    for (i = 0; i < V; i++)
    {                                          stepcount++;
        for (j = 0; j < V; j++)
        {                                       stepcount+=2;
            dist[i][j] = graph[i][j];       
        }   
    }                                           stepcount+=2;

    /* Set of intermediate vertices. */
    for (k = 0; k < V; k++)
    {                                           stepcount++;
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {                                       stepcount++;
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {                                   stepcount+=2;
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])   
                    dist[i][j] = dist[i][k] + dist[k][j];   
            }
        }
    }                                           stepcount+=3;

    // Print the shortest distance matrix
    printOutputMatrix(dist);
}

// MAIN FUCNTION ===> 
int main()
{
    /* Read number of vertices */
    printf("\nEnter the number of vertices: ");
    scanf("%d", &V);                           stepcount++;

    int i, j;

    /* Read Edges; For all non-diagonal elements that are zero
    equate them to INF (large) value */
    printf("\nEnter the cost of edges:(matrix form)");
    for (i = 0; i < V; i++)
    {                                          stepcount++;
        for (j = 0; j < V; j++)
        {                                      stepcount++;
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;             stepcount+=2;
        }
    }                                          stepcount+2;

    AllPairsShortestPath();

    printf("(Stepcount = %d)", stepcount);
    return 0;
}
