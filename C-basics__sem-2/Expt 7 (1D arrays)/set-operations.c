/*
Write a program to implement following Set Operations:
• Union of two sets
• Intersection of two sets
*/

#include <stdio.h>

#define SIZE 100

// function declarations
int readValues(int arr[]);
void unionOfSets(int set1[], int set2[], int size1, int size2);
void intersectionOfSets(int set1[], int set2[], int size1, int size2);

int main()
{
    int set1[SIZE], set2[SIZE];

    printf("\t---Program to perform Union and Intersection of two sets---");

    printf("\nEnter the elements of Set 1 (enter -1 to mark end):-\n");
    int size_1 = readValues(set1);

    printf("\nEnter the elements of Set 2 (enter -1 to mark end):-\n");
    int size_2 = readValues(set2);

    // function calls
    unionOfSets(set1, set2, size_1, size_2);            // compute Union of the sets
    intersectionOfSets(set1, set2, size_1, size_2);     // compute Intersection of sets

    return 0;
}

int readValues(int arr[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] == -1)  
            break;
    }

    return i; // return array size
}

void unionOfSets(int set1[], int set2[], int size1, int size2)
{
    int unionSet[SIZE], i, j;
    int count = 0;
    int flag = 0;

    // add all elements of set1 to union-set
    for (i = 0; i < size1; i++)
        unionSet[i] = set1[i];

    int currentUnionPos = i;

    // check if value in set2 is unique to both sets
    for (i = 0; i < size2; i++)
    {
        for (j = 0; j < currentUnionPos; j++)
            if (set2[i] == unionSet[j]) // check if the value in set-2 is common with unionSet, if so, do not add to Union
                flag++;

        // if value in set-2 is unique, add to the Union
        if (flag == 0)
        {
            unionSet[currentUnionPos] = set2[i];
            currentUnionPos++;
        }
        else
            flag = 0;
    }

    // print the values of Union
    printf("\n\nThe union of set-1 and set-2:\n\t{");
    for (i = 0; i < currentUnionPos; i++)
        printf(" %d,", unionSet[i]);
    printf("}");
}

void intersectionOfSets(int set1[], int set2[], int size1, int size2)
{
    int i, j;
    int intersectionSet[SIZE];

    int k = 0;
    int flag = 0;

    // if a value is common to both sets, add to Intersection
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            if (set1[i] == set2[j])
            {
                flag++;
                break;
            }
        }

        if (flag) // if flag is non-zero, then the value is common to both sets
        {
            intersectionSet[k] = set1[i]; // add common value to Intersection
            k++;
            flag = 0;
        }
    }

    // display intersection set
    printf("\n\nThe intersection of set-1 & set-2 is:\n\t{");
    for (i = 0; i < k; i++)
    {
        printf(" %d,", intersectionSet[i]);
    }
    printf("}");
}