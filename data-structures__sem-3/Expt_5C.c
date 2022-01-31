// Write a program to  display the width and the level of binary tree.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

// To Insert in BT
void insertBin()
{
    int data;
    struct node *tmp, *par, *ptr;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);
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
            printf("\nDulplicate Key");
            return;
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
    return;
}

// To get width at given level
int getWidth(struct node *root, int level)
{

    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
        return getWidth(root->lchild, level - 1) + getWidth(root->rchild, level - 1);
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        // compute the height of each subtree
        int lHeight = height(node->lchild);
        int rHeight = height(node->rchild);

        return (lHeight > rHeight) ? (lHeight + 1)
                                   : (rHeight + 1);
    }
}

// To get max width
int getMaxWidth()
{
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;
    int lvl;

    for (i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if (width > maxWidth)
        {
            maxWidth = width;
            lvl = i;
        }
    }
    printf("\nMax width is : %d", maxWidth);
    printf("\nMax Width level: %d", lvl);
}
// Main Function
int main()
{
    int num, i;
    printf("\nHow many elements do you want to insert?");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        insertBin();
    }
    // Print Max width
    getMaxWidth();
    return 0;
}
