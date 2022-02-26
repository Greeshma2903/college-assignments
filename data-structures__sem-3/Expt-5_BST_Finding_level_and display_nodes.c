// 	4. WAP that input a level and display the nodes on that level from lchild to rchild.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
// Insert Elements
struct node *insertBin(struct node *root, int data)
{
    struct node *tmp, *par, *ptr;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (data < ptr->data)
        {
            ptr = ptr->lchild;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            printf("\n=> Dulplicate Key");
            return root;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
        root = tmp;
    else if (data < par->data)
    {
        par->lchild = tmp;
    }
    else
        par->rchild = tmp;
    return root;
}
// Display Tree
void display(struct node *p, int level)
{
    int i;
    if (p == NULL)
        return;
    display(p->rchild, level + 1);
    printf("\n");

    for (i = 0; i < level; i++)
    {
        printf("   ");
    }
    if (p->rchild != NULL && p->lchild != NULL)
        printf("%d <", p->data);
    else if (p->rchild != NULL && p->lchild == NULL)
        printf("%d /", p->data);
    else if (p->rchild == NULL && p->lchild != NULL)
        printf("%d \\", p->data);
    else
        printf("%d  ", p->data);

    display(p->lchild, level + 1);
}
// Print elements at level
void printNodes(struct node *root, int currentLevel, int level)
{

    if (root == NULL)
    {
        return;
    }
    if (currentLevel == level)
    {
        printf(" %d ", root->data);
        return;
    }
    printNodes(root->lchild, currentLevel + 1, level);
    printNodes(root->rchild, currentLevel + 1, level);
}
// MAIN FUCNCTION
int main()
{
    struct node *root = NULL;
    int num, i, data, lvl;
    printf("\nHow many elements do you want to insert?");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\nEnter data to be inserted: ");
        scanf("%d", &data);
        root = insertBin(root, data);
    }
    display(root, 0);

    printf("\n\nEnter a level:");
    scanf("%d", &lvl);
    printf("\n=> Elements at level %d :", lvl);
    printNodes(root, 1, lvl);

    return 0;
}