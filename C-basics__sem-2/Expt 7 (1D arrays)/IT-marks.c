/*
Q5. WAP to accept the IT1 and IT2 marks of students for the subject of Comp Prog. Additionally store that IT averages as ITAVG. Compute the class average of the ITAVG and print the indices and marks of those students who have score above class average.
*/

#include <stdio.h>
#define SIZE 100

// function declarations
int readValues(int arr[], int arrSize);
int calcStudentITAvg(int test1[], int test2[], int noStudents, int ITAVG[]);
int computeClassAvg(int ITAVG[], int arrSize);
int computeAboveAvgStudents(int studentAvg[], int test1[], int test2[], int noStudents, int classAvg);


int main()
{
    int internals1[SIZE], internals2[SIZE], noStudents, ITAVG[SIZE];

    printf("\t---Program to calculate class average in IT's and more---");

    printf("\nEnter the number of students:", noStudents);  // input array limit
    scanf("%d", &noStudents);

    // Read marks for respective IT's
    printf("\nEnter the marks of student in IT1 (out of 25):\n");
    readValues(internals1, noStudents); // TODO: array-size contains -1's place, ig ignore

    printf("\nEnter the marks of student in IT2 (out of 25):\n");
    readValues(internals2, noStudents);
	
	// function callS
    calcStudentITAvg(internals1, internals2, noStudents, ITAVG);    // to calculate average of each student 
    int classAvg = computeClassAvg(ITAVG, noStudents);              // to calculate class average
	
	printf("\nThe class average is: %d", classAvg);
	
    printf("\nThe students who scored above class average (with respective marks):- \n");
    // function call: display student marks whose avg is above class-average
    computeAboveAvgStudents(ITAVG, internals1, internals2, noStudents, classAvg);   

    return 0;
}

// function to read array values
int readValues(int arr[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// function to calculate average marks of weach student
int calcStudentITAvg(int test1[], int test2[], int noStudents, int ITAVG[])
{
    int i;
    for (i = 0; i < noStudents; i++)
    {
        ITAVG[i] = (test1[i] + test2[i]) / 2;
    }
}

int computeClassAvg(int ITAVG[], int arrSize)
{
    int sum = 0, i;
    for (i = 0; i < arrSize; i++)
    {
        sum += ITAVG[i];
    }

    int classAvg = sum / arrSize;
    return classAvg;
}

// compare and display marks of student whose average is above class-average
int computeAboveAvgStudents(int studentAvg[], int test1[], int test2[], int noStudents, int classAvg)
{
    int i;
    for (i = 0; i < noStudents; i++)
    {
        if (studentAvg[i] > classAvg)
        {
            printf("Index %d --- Student marks: %d & %d\n", i, test1[i], test2[i]);
        }
    }
}
