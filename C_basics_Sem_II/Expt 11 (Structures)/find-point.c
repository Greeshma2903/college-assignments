/*
Implement a structure for Points. Each point has the x and y coordinate. Write appropriate
functions to accept points from user and print the points. Write a function to find distance
between any two points. Create an array of Points and find the two points which are closest
to each other.
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    int x, y;
} Points;

Points p[10];
// function declarations
void acceptPoints(Points *ptr);
void printPoints(Points *ptr);
int computeDistance(Points *ptr1, Points *ptr2);
void findClosestPoints(float matrix[][10], int numPoints);

int main()
{
    int i, size;
    float distance, matDist[10][10];
    Points dist[2];

    // ask users to enter two points
    printf("To find distance, enter two points:-");
    for (i = 0; i < 2; i++)
    {
        printf("\nEnter coordinates of point %d -", i + 1);
        acceptPoints(&dist[i]);
    }
    printf("\n\nFollowing are the points you entered:-");
    for (i = 0; i < 2; i++)
        printPoints(&dist[i]);

    distance = computeDistance(&dist[0], &dist[1]);     // function call to calculate distance btw points
    printf("\nThe distance between the points is: %f", distance);

    printf("\n------------------------------------------/");
    printf("\nEnter an array of points below ---");
    printf("\n\nHow many points do you want to enter? (<10) :");
    scanf("%d", &size);

    // function call to find closest points within array
    findClosestPoints(matDist, size);

    return 0;
}

// function to read points
void acceptPoints(Points *ptr)
{
    printf("\n\tx:");
    scanf("%d", &(ptr->x));
    printf("\ty:");
    scanf("%d", &(ptr->y));
    printf("-------------/");
}

// function to print points
void printPoints(Points *ptr)
{
    printf("\n\t(%d, %d)", ptr->x, ptr->y);
}

// function to compute distance btw two points
int computeDistance(Points *ptr1, Points *ptr2)
{
    float distance;
    distance = sqrt(pow((ptr1->x - ptr2->x), 2) + pow((ptr1->y - ptr2->y), 2) * 1.0);

    return distance;
}

// function to find closest point among array of points
void findClosestPoints(float matrix[10][10], int numPoints)
{
    int i, j, row, col;
    float min;

    // to read points
    for (i = 0; i < numPoints; i++)
    {
        printf("\nEnter coordinates of point %d -", i + 1);
        acceptPoints(&p[i]);
    }
    float k;

    // to input the distances btw all point-pairs into the sq. matrix
    for (i = 0; i < numPoints; i++)
        for (j = 0; j < numPoints; j++)
        {
            matrix[i][j] = sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2) * 1.0);
        }

    // to find smallest value in matrix, and return associated row and column number
    min = matrix[0][1];     // cannot be mat[0][0] since value is 0

    for (i = 0; i < numPoints; i++)
    {
        for (j = 0; j < numPoints; j++)
        {
            if (i != j)
            {
                if (matrix[i][j] <= min)
                {
                        min = matrix[i][j];
                        row = i;
                        col = j;
                }
            }

        }
    }

    // print values
    printf("\nThe closeset points are: (%d, %d) and (%d, %d)", p[row].x, p[row].y, p[col].x, p[col].y);
    printf("\n... and the closest distance : %f", min);
}
    /*
        printf("\nThe Matrix values:\n");
    for (i = 0; i < numPoints; i++)
    {
        for (j = 0; j < numPoints; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
    */

