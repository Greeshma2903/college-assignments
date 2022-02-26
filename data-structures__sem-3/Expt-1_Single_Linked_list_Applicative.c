/*
    WAP to generate a student record using LL.
    RollNo, Std, Marks (s1, s2, s3), total, avg
    1. Find the largest and smallest element in the linked list
    2. Swap the adjacent element by rearranging links
    3. Merge 2 linked list
    4. Split the 2 linked lists (based on roll no) 

-- Record
    -- How many
    -- create list
        -- addBeg
        -- addEnd
    
    
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentRecord
{
    char name[40];
    int roll, std;
    float marks[3], total, avg;
    struct studentRecord *link;
} * start, *start_2, *start_3;

struct studentRecord *createRecord(struct studentRecord *head);
struct studentRecord *addBeg(struct studentRecord *head);
void addEnd(struct studentRecord *head);
void displayList(struct studentRecord *head);
void findHighLow();
struct studentRecord *swapAdjacentNodes(struct studentRecord *start);
void mergeList();
struct studentRecord *sort(struct studentRecord *head);
void split();

/* ---------------- MAIN FUNCTION----------------  */
int main()
{
    int i, option;
    start = NULL;
    start_2 = NULL; // for 2nd linked list

    printf("\n =========================== WELCOME ==============================");
    do
    {
        printf("\n*****************************************");
        printf("\nChoose from the following: -");
        printf("\n1. Create a student record \n2. Find the highest and lowest score \n3. Swap the adjacent elements \n4. Merge another linked list \n5. Split the linked list (based on roll numbers \n6. Exit");
        printf("\n*****************************************\n");

        printf("\nEnter an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: // create student records
            start = createRecord(start);
            printf("\n--------------------------------------------\n");
            break;
        case 2:
            findHighLow();
            printf("\n--------------------------------------------\n");
            break;
        case 3:
            start = swapAdjacentNodes(start);
            printf("\n--------------------------------------------\n");
            break;
        case 4:
            printf("\n=> Enter another set of student records for merging:------------\n");
            start_2 = createRecord(start_2);
            start_3 = NULL;
            mergeList();
            break;
        case 5:
            printf("\n");
            split();
            break;
        case 6:
            option = 6;
            break;
        default:
            printf("\nINVALID OPTION!");
            break;
        }
    } while (option != 6);

    return 0;
}

// FUNCTION:    to initiate student record
struct studentRecord *createRecord(struct studentRecord *head)
{
    int num, i;
    head = NULL;
    printf("\nHow many records do you want to create? ");
    scanf("%d", &num);
    if (num == 0)
        return head;

    printf("\nEnter the 1st student record: ");
    head = addBeg(head);

    for (i = 2; i <= num; i++)
    {
        printf("\nEnter %d student record: ", i);
        addEnd(head);
    }
    displayList(head);
    return head;
}

// FUNCTION:    Add record at the beginning
struct studentRecord *addBeg(struct studentRecord *head)
{
    int i;
    struct studentRecord *tmp;
    tmp = (struct studentRecord *)malloc(sizeof(struct studentRecord));

    // Read details
    printf("\nEnter roll no: ");
    scanf("%d", &tmp->roll);
    printf("Enter Class/Std: ");
    scanf("%d", &tmp->std);
    getchar();
    printf("Enter name: ");
    fgets(tmp->name, sizeof(tmp->name), stdin);
    printf("\nEnter marks:\n");
    for (i = 0; i < 3; i++)
    {
        printf("\tSubject %d: ", i + 1);
        scanf("%f", &tmp->marks[i]);
    }

    tmp->total = 0;
    for (i = 0; i < 3; i++)
        tmp->total += tmp->marks[i];
    tmp->avg = tmp->total / 3;

    // add node at head
    tmp->link = head;
    head = tmp;
    return head;
}

// FUNCTION:    Add record at the end
void addEnd(struct studentRecord *head)
{
    int i;
    struct studentRecord *tmp, *p;
    p = head;
    tmp = (struct studentRecord *)malloc(sizeof(struct studentRecord));

    // Read details
    printf("\nEnter roll no: ");
    scanf("%d", &tmp->roll);
    printf("Enter Class/Std: ");
    scanf("%d", &tmp->std);
    printf("Enter name: ");
    fflush(stdin);
    fgets(tmp->name, sizeof(tmp->name), stdin);

    printf("\nEnter marks:\n");
    for (i = 0; i < 3; i++)
    {
        printf("\tSubject %d: ", i + 1);
        scanf("%f", &tmp->marks[i]);
    }
    tmp->total = 0;
    for (i = 0; i < 3; i++)
        tmp->total += tmp->marks[i];

    tmp->avg = tmp->total / 3;

    // move pointer till end of list
    while (p->link != NULL)
    {
        p = p->link;
    }
    // add node at end
    p->link = tmp;
    tmp->link = NULL;
}

// FUNCTION:    to display linked list
void displayList(struct studentRecord *head)
{
    int i;
    if (head == NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    struct studentRecord *p = head;
    int count = 0;

    while (p != NULL)
    {
        printf("\n-----------------------------\n");
        printf("\nStudent %d:---\n", count + 1);
        printf("Roll number: %d", p->roll);
        printf("\nName: %s", p->name);
        printf("Class: %d", p->std);
        printf("\nMarks:\n");
        for (i = 0; i < 3; i++)
        {
            printf("\tSubject %d: %.2f", i, p->marks[i]);
        }
        printf("\nTotal marks: %.2f", p->total);
        printf("\nAverage : %.2f\n\n", p->avg);

        p = p->link; // move forward
        ++count;
    }
}

// FUNCTION:    to find and display highest and lowest score
void findHighLow()
{
    int max, min;
    struct studentRecord *p, *q, *r;
    if (start == NULL)
    {
        printf("\nThe list is empty.");
        return;
    }

    p = start;
    // give initial values
    max = p->total;
    min = p->total;

    // find min and max
    while (p != NULL)
    {
        if (p->total > max)
        {
            max = p->total;
        }
        p = p->link;
    }

    p = start;
    while (p != NULL)
    {
        if (p->total < min)
        {
            min = p->total;
        }
        p = p->link;
    }

    p = start;
    while (p != NULL)
    {
        if (max == p->total)
            printf("\n%s - has scored highest marks i.e. %f", p->name, p->total);
        p = p->link;
    }

    p = start;
    while (p != NULL)
    {
        if (min == p->total)
            printf("\n%s - has scored lowest marks i.e. %f", p->name, p->total);
        p = p->link;
    }

    p = start;
    if (start->total == min)
    {
        q = start;
        while (p->link != NULL)
            p = p->link;
        p->link = q;
        start = q->link;
        q->link = NULL;
    }
    else
    {
        for (p = start, q = start->link; q != NULL;)
        {
            if (q->total == min && q->link != NULL)
            {
                for (r = start; r->link != NULL; r = r->link);
                p->link = q->link;
                r->link = q;
                q->link = NULL;
                break;
            }
            p = q;
            q = q->link;
        }
    }
    printf("\nList after moving the smallest element to the end: ----------------\n");
    displayList(start);
}

// FUNCTION:    Swap the adjacent elements
struct studentRecord *swapAdjacentNodes(struct studentRecord *start)
{
    struct studentRecord *cur, *next, *prev;
    if (start->link == NULL || start == NULL)
    {
        printf("\nInsufficient records to swap with!");
        return start;
    }
    cur = start;
    prev = NULL;

    while (cur->link != NULL && cur != NULL)
    {
        next = cur->link;
        cur->link = next->link;
        next->link = cur;
        if (prev == NULL)
        {
            start = next; // for first node
        }
        else
        {
            prev->link = next; // for other nodes
        }

        prev = cur;
        cur = cur->link;
    }
    displayList(start);
    return start;
}

// FUNCTION: to merge two linked list
void mergeList()
{
    struct studentRecord *p, *m, *tmp;
    p = start;
    m = start_2;
    int i, temp, j;
    // Merging of Lists
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = start_2;

    printf("\nOriginal Merged List:-------------------------\n");
    displayList(start);
    printf("\n----------------------------------------------\n");

    // sorting
    start = sort(start);
    printf("\nThe sorted list --------------------------------\n");
    displayList(start);
    printf("\n------------------------------------------------\n");
}

// FUNCTION: to sort the list
struct studentRecord *sort(struct studentRecord *head)
{
    struct studentRecord *u = head, *v, temp_1, temp_2;

    while (u->link != NULL)
    {
        v = u->link;
        temp_1 = *u;
        while (v != NULL)
        {
            if (v->roll < u->roll)
            {
                temp_2 = *v;
                *v = *u;
                *u = temp_2;
                u->link = temp_1.link;
                v->link = temp_2.link;
            }
            v = v->link;
        }
        u = u->link;
    }
    return head;
}

// FUNCTION: to split the array into half
void split()
{
    struct studentRecord *p;
    int count = 0, i;
    for (p = start; p != NULL; p = p->link)
    {
        ++count;
    }

    int half = count / 2;
    p = start;
    for (i = 1; i < half; i++)
    {
        p = p->link;
    }

    struct studentRecord *start_4 = p->link;
    p->link = NULL;
    printf("\nThe 1st half of Split Linked list: -----------------------------\n");
    displayList(start);
    printf("\nThe 2nd half of Split Linked list: -----------------------------\n");
    displayList(start_4);
}
