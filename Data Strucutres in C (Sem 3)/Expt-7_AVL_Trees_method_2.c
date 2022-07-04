#include<stdio.h>
#include<stdlib.h>
#define Count 5
struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;	
}*root;

struct node *insert(struct node *root, int item);
struct node *delete(struct node *ptr, int item);
void display(struct node *root,int space);
int height(struct node *root);
int balanceFactor(struct node *root);
struct node *rotateLeft(struct node *ptr);
struct node *rotateRight(struct node *ptr);

int main()
{
	int choice,item;
	root = NULL;
	
	while(1)
	{
		printf("1.Insert a node\n");
		printf("2.Delete a node\n");
		printf("3.Display tree\n");
		printf("4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
					
			case 1: printf("Enter item to be inserted: ");
					scanf("%d",&item);
					root = insert(root,item);
					printf("\n-----------------------------------\n");
					break;
					
	        case 2: printf("Enter item to be deleted: ");
					scanf("%d",&item);
					root = delete(root,item);
					printf("\n-----------------------------------\n");
					break;
					
			case 3: if (root == NULL)
					{
						printf("Binary Search Tree is empty\n");
						printf("\n-----------------------------------\n");
						break;
					}
					else
					{
						display(root,0);
						printf("\n-----------------------------------\n");
					}
					break;
					
			case 4: return 0;
			
			default:printf("Invalid choice\n");
					break;
		}
	}
}

struct node* insert(struct node *ptr,int item)
{
	if(ptr==NULL)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->info = item;
	}else if(item<ptr->info)
		ptr->lchild=insert(ptr->lchild, item);
	else if(item>ptr->info)
		ptr->rchild=insert(ptr->rchild, item);
	else
		printf("Duplicate Item!");
	int balance = balanceFactor(root);
	if(balance>1 && ptr->lchild->info>item)
	{
		ptr = rotateLeft(ptr);
	}
	if(balance<-1 && ptr->rchild->info<item)
	{
		ptr = rotateRight(ptr);
	}
	if(balance>1 && ptr->lchild->info<item)
	{
		ptr->lchild = rotateRight(ptr->lchild);
		ptr = rotateLeft(ptr);
	}
	if(balance<-1 && ptr->rchild->info>item)
	{
		ptr->rchild = rotateLeft(ptr->rchild);
		ptr = rotateRight(ptr);
	}
	return ptr;
}

struct node *delete(struct node *ptr, int item)
{
	struct node *tmp, *succ;
	if(ptr==NULL)
	{
		printf("Item not found in tree");
		return ptr;
	}
	if(item<ptr->info)          //delete element from left subtree
		ptr->lchild=delete(ptr->lchild, item);
	else if(item>ptr->info)
		ptr->rchild=delete(ptr->rchild, item);
	else
	{
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			succ=ptr->rchild;
			while(succ->lchild!=NULL)
			{
				succ=succ->lchild;
			}
			ptr->info=succ->info;
			ptr->rchild=delete(succ, succ->info);
		}else
		{
			tmp=ptr;
			if(ptr->lchild==NULL)
			{
				ptr=NULL;
				free(tmp);
			}
			else
			{
				if(ptr->lchild!=NULL)
				{
					tmp=ptr->lchild;
					ptr=tmp;
					free(tmp);
				}else
				{
					tmp=ptr->rchild;
					ptr=tmp;
					free(tmp);
				}
			}
		}
	}
	if(ptr==NULL)
		return NULL;
	int balance = balanceFactor(ptr);
	if(balance>1 && balanceFactor(ptr->lchild)>=0)
	{
		ptr = rotateLeft(ptr);
	}
	if(balance<-1 && balanceFactor(ptr->rchild)<=0)
	{
		ptr = rotateRight(ptr);
	}
	if(balance>1 && balanceFactor(ptr->lchild)<0)
	{
		ptr->lchild = rotateRight(ptr->lchild);
		ptr = rotateLeft(ptr);
	}
	if(balance<-1 && balanceFactor(ptr->rchild)>0)
	{
		ptr->rchild = rotateLeft(ptr->rchild);
		ptr = rotateRight(ptr);
	}
	return ptr;
}

void display(struct node *ptr,int space)
{
    int i;
    if (ptr == NULL)
      return;
    space += Count;
    display(ptr->rchild, space);
    for (i = Count; i < space; i++)
        printf(" ");
    if (ptr->lchild!=NULL || ptr->rchild!=NULL)
    	printf("%d <\n",ptr->info);
    else
    	printf("%d	\n",ptr->info);
    display(ptr->lchild, space);
}
int count( struct node *ptr)
{
	if(ptr == NULL)
		return 0;
	if(ptr->lchild == NULL && ptr->rchild == NULL)
	{
		printf("%d ", ptr->info);
		return 1;
	}
	return count(ptr->lchild) + count(ptr->rchild); 
}

int height(struct node *ptr)
{
	if (ptr == NULL)
	{
		return 0;	
	}
	int h_left_subtree;
	int h_right_subtree;
	h_left_subtree = height(ptr->lchild);
	h_right_subtree = height(ptr->rchild);
	
	if (h_right_subtree > h_left_subtree)
	{
		return 1 + h_right_subtree;	
	}	
	else
		return 1 + h_left_subtree;
	
}

int balanceFactor(struct node *ptr)
{
	if(ptr==NULL)
	{
		return 0;
	}else
	{
		return (height(ptr->lchild) - height(ptr->rchild));
	}
}

struct node *rotateLeft(struct node *ptr)
{
	struct node *aptr;
	aptr=ptr->lchild;
	ptr->lchild=aptr->rchild;
	aptr->rchild=ptr;
	return aptr;
}

struct node *rotateRight(struct node *ptr)
{
	struct node *aptr;
	aptr=ptr->rchild;
	ptr->rchild=aptr->lchild;
	aptr->lchild=ptr;
	return aptr;
}
