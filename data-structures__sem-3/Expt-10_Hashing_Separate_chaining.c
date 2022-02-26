// D) WAP to implement separate chaining
//    I) Insert II) Delete III) Search IV) Display  table
#include <stdio.h>
#include<stdlib.h>
#define MAX 11

struct student
{
	int id;
	char name[20];
	int gradepoint;
};

struct Record 
{
	struct student data;
	struct Record *link;
};
// GENERATE HASH
int hash(int key)
{
	return (key%MAX);
}
// SEARCH THE RECORD
int search(int key, struct Record *table[])
{
	int h;
    struct Record *ptr;
	h = hash(key);				
	ptr = table[h];
	while(ptr!=NULL)
	{
		if(ptr->data.id == key)
			return h;
		ptr = ptr->link;
	}
	return -1;
}
// INSERT THE RECORD
void insert(struct student st, struct Record *table[])
{
	int h, key;
	struct Record *tmp;

	key = st.id; 
		
	if(search(key, table)!=-1)
	{
		printf("Duplicate key\n");
		return;
	}
    h = hash(key);				
	/*Insert in the beginning of list h*/
	tmp=malloc(sizeof(struct Record));
	tmp->data = st;
	tmp->link = table[h];
	table[h] = tmp;
}
// DISPLAY TABLE
void display(struct Record *table[])
{
	int i;
	struct Record *ptr;
	for(i=0; i<MAX; i++)
	{
		printf("\n[%d]  ",i);
		if(table[i]!=NULL)
		{
			ptr=table[i];
			while(ptr!=NULL)
			{
				printf("%d %s %f\t", ptr->data.id, ptr->data.name, ptr->data.gradepoint);
				ptr=ptr->link;
			}
		}
	}
	printf("\n");
}
// DELETE A RECORD
void del(int key, struct Record *table[])
{
	int h;
    struct Record *tmp, *ptr;
	h = hash(key);				
	
	if(table[h]==NULL)
	{
		printf("Key %d not found\n", key);
		return;
	}
	if(table[h]->data.id == key)
	{
		tmp=table[h];
		table[h]=table[h]->link;  
		free(tmp);
		return;
	}
	ptr = table[h];
	while(ptr->link!=NULL)
	{
		if(ptr->link->data.id == key)   
		{
			tmp=ptr->link;
			ptr->link=tmp->link;
			free(tmp);
			return;
		}
		ptr=ptr->link;
	}
	printf("Key %d not found\n",key);
}

int main()
{
	struct Record *table[MAX];	
	struct student st;
	int i,key,choice;
	
	for(i=0; i<=MAX-1; i++)
		table[i] = NULL;

	while(1)
	{
		printf("\n--------------------------\n");
		printf("1. Insert a record\n2. Search a record\n3. Delete a record\n4. Display table\n5. Exit\nEnter your choice\n");
		scanf("%d",&choice);
        printf("\n--------------------------\n");

		switch(choice)
		{
			case 1 : 
				printf("Enter the record\n");
				printf("Enter id, name, gradepoint  : ");
				scanf("%d %s %f",&st.id,&st.name,&st.gradepoint);
				insert(st, table);
				break;
			case 2 : 
				printf("Enter a key to be searched : ");
				scanf("%d", &key);
				i = search(key, table);
				if(i==-1)
					printf("Key not found\n");
				else
					printf("Key found in chain %d\n", i);
				break;
			case 3: 
				printf("Enter a key to be deleted\n");
				scanf("%d",&key);
				del(key,table);
				break;
			case 4:
				display(table);
				break;
			case 5:
				exit(1);
		}
	}
    return 0;
}
