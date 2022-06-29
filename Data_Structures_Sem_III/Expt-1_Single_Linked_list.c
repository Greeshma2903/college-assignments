/*
 To write a C program with of single linked list with the following operations:
	1. Create a linked list
	2. Display linked list
	3. Count the no of node on linked list
	4. Search for an element and display its position
	5. Add a node at the end, at the beginning, after a node, before a node, at a particular position.
	6. Delete a node
    7.Reverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// FUNCTIONS
void addToFile(FILE *fp, struct node *start)
{
    struct node *p;
    p = start;
    fprintf(fp, "\nThe list is: \n");
    while (p->link != NULL)
    {
        fprintf(fp, "%d  ", p->data);
        p = p->link;
    }
    fprintf(fp, "%d\n", p->data);
}

// add at beginning
struct node *addBeg(struct node *start, int data, FILE *fp)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node)); // DMA to tmp
    tmp->data = data;
    tmp->link = start;
    start = tmp;
    // display operation to files
    fprintf(fp, "\n%d was added at beginning of the node", data);
    addToFile(fp, start);
    return start;
}

// add at the end
struct node *addEnd(struct node *start, int data, FILE *fp)
{
    struct node *tmp, *p;
    p = start;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    while (p->link != NULL)
        p = p->link; // move pointer to the last node on list

    p->link = tmp;
    tmp->link = NULL;
    fprintf(fp, "%d was added at the end of node", data);
    addToFile(fp, start);
    return start;
}

// create the list
struct node *createList(struct node *start, FILE *fp)
{
    int numNodes, i, data;
    printf("\nHow many nodes do you want to add?");
    scanf("%d", &numNodes);
    start = NULL;
    if (numNodes == 0)
        return start;

    printf("\nEnter data for node:");
    scanf("%d", &data);
    start = addBeg(start, data, fp);
    for (i = 1; i < numNodes; i++)
    {
        printf("\nEnter data for node:");
        scanf("%d", &data);
        start = addEnd(start, data, fp);
    }
    fprintf(fp, "\nNew list was created");
    addToFile(fp, start);
    return start;
}

// display the list
void displayList(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    p = start;
    printf("\nThe list is: \n");
    while (p->link != NULL)
    {
        printf("%d\n", p->data);
        p = p->link;
    }
    printf("%d\n", p->data);
}

// count the nodes
void countNodes(struct node *start, FILE *fp)
{
    int count = 1;
    struct node *p;
    if (start == NULL)
    {
        printf("\nThere are no nodes on the list");
        return;
    }
    // count number of elements
    p = start;
    while (p->link != NULL)
    {
        p = p->link;
        ++count; // keeps track of the number of elements
    }
    printf("\nThe Linked list has %d number of nodes", count);
    fprintf(fp, "\nThe Linked list has %d number of nodes", count);
    addToFile(fp, start); // add operation to list
}

// search an element
void searchElement(struct node *start)
{
    int ele, pos = 0;
    struct node *p;

    if (start == NULL)
    {
        printf("\nThe list is empty");
        return;
    }

    printf("\nEnter the element you want to search: ");
    scanf("%d", &ele);

    p = start;
    // search the list
    while (p != NULL)
    {
        pos++; // keeps track of position
        if (p->data == ele)
        {
            printf("\n\tElement %d found at position %d", ele, pos);
            return;
        }
        p = p->link;
    }
    printf("\n\tElement not found");
}

// insert element bef
struct node *insertBefore(struct node *start, int data, int ele, FILE *fp)
{
    struct node *p, *tmp;
    int flag = 0;
    if (start == NULL)
    {
        printf("\nThe list is empty.");
        return start;
    }
    if (ele == start->data) // if element is at start of list
    {
        start = addBeg(start, data, fp);
        return start;
    }
    p = start; // if element not at start of list
    while (p->link != NULL)
    {
        if (p->link->data == ele)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->link = p->link;
            p->link = tmp;
            fprintf(fp, "\n%d inserted before element %d.", data, ele);
            addToFile(fp, start);
            return start;
        }
        p = p->link;
    }

    printf("\nElement not found");
}

struct node *insertAfter(struct node *start, int data, int ele, FILE *fp)
{
    struct node *p, *tmp;
    p = start;
    while (p->link != NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = data;
        if (p->data == ele)
        {
            tmp->link = p->link;
            p->link = tmp;
            fprintf(fp, "\n%d element added after %d", ele, data);
            addToFile(fp, start);
            return start;
        }
        p = p->link;
    }

    printf("\nElement not found");
}

struct node *insertPosition(struct node *start, int data, int pos)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    int i;
    tmp->data = data;
    if (pos == 1)
    {
        tmp->link = start;
        start = tmp;
        return start;
    }

    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->link;
    }
    if (p == NULL)
        printf("\nThere are less than %d elements", pos);
    else
    {
        tmp->link = p->link;
        p->link = tmp;
    }
}

struct node *delete (struct node *start, FILE *fp)
{
    int ele, flag = 0;
    struct node *tmp, *p;
    printf("\nEnter the element you want to delete: ");
    scanf("%d", &ele);
    if (start == NULL)
    {
        printf("\nThe list is empty, cannot perform deletion.");
        return start;
    }
    if (ele == start->data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->data == ele)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            fprintf(fp, "\n%d is deleted.", ele);
            addToFile(fp, start);
            return start;
        }
        p = p->link;
    }

    printf("\nElement not found!");
    return start;
}

struct node *reverseList(struct node *start, FILE *fp)
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = start;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    fprintf(fp, "\nThe list has been reversed.");
    addToFile(fp, start);

    return start;
}

int main()
{
    int i, option, data, pos;
    struct node *start = NULL;
    FILE *fp;
    fp = fopen("NodeList.txt", "w");
    fclose(fp);
    fp = fopen("NodeList.txt", "r+");

    printf("----------Single Linked List Program----------------");
    do
    {
        printf("\nSelect the operation from the following:\n");
        printf("\n1. Create a linked list");
        printf("\n2. Display a linked list");
        printf("\n3. Count the number of nodes on the linked list");
        printf("\n4. Search for an element and search for its position");
        printf("\n5. Add a node at the end");
        printf("\n6. Add node at the beginning");
        printf("\n7. Add a node before a node");
        printf("\n8. Add a node after a node");
        printf("\n9. Add a node at a particular position");
        printf("\n10. Delete a node");
        printf("\n11. Reverse a node");
        printf("\n12. Exit");
        printf("\n\nEnter option:");
        scanf("%d", &option);
        printf("-----------------------------------------------");

        switch (option)
        {
        case 1: // create a linked list
            start = createList(start, fp);
            printf("\n--------------------------------");
            break;
        case 2: //  display a linked list
            displayList(start);
            printf("\n--------------------------------");
            break;
        case 3: // count nodes on the list
            countNodes(start, fp);
            printf("\n--------------------------------");
            break;
        case 4: // search given element and display its position
            searchElement(start);
            printf("\n--------------------------------");
            break;
        case 5: // Add a node at the end
            printf("\nEnter the data:");
            scanf("%d", &data);
            start = addEnd(start, data, fp);
            printf("\n--------------------------------");
            break;
        case 6: // Add a node at the beginning
            printf("\nEnter the data:");
            scanf("%d", &data);
            start = addBeg(start, data, fp);
            printf("\n--------------------------------");
            break;
        case 7: // Add a node before a node
            printf("\nEnter the data: ");
            scanf("%d", &data);
            printf("\nBefore which element do you want to add node? : ");
            scanf("%d", &pos);
            start = insertBefore(start, data, pos, fp);
            printf("\n--------------------------------");
            break;
        case 8: // Add a node after a node
            printf("\nEnter the data: ");
            scanf("%d", &data);
            printf("\nBefore which element do you want to add node? : ");
            scanf("%d", &pos);
            start = insertAfter(start, data, pos, fp);
            printf("\n--------------------------------");
            break;
        case 9: // to insert element at a particular position
            printf("\nEnter the position at which you want to add element:");
            scanf("%d", &pos);
            printf("\nEnter the data: ");
            scanf("%d", &data);
            start = insertPosition(start, data, pos);
            printf("\n--------------------------------");
            break;
        case 10: // to delete a node on the linked list
            start = delete (start, fp);
            printf("\n--------------------------------");
            break;
        case 11: // to reverse the linked list
            start = reverseList(start, fp);
            printf("\n--------------------------------");
            break;
        case 12: // quit
            option = 12;
            break;
        default:
            printf("\nInvalid Option!");
            break;
        }
    } while (option != 12);
    fclose(fp);
    return 0;
}
