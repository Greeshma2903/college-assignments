// B) WAP to implement closed hashing with  quadratic probing.
    // I) Insert II) Delete III) Search IV) Display table

#include <stdio.h>
#include<stdlib.h>
#define MAX 10

enum type_of_record {EMPTY, DELETED,OCCUPIED};

struct student
{
	int id;
	char name[20];
	float gradepoint;
};
struct Record
{
	struct student data;
	enum type_of_record status;
};	

int hash(int key)
{
	return (key%MAX);
}
// SEARCH RECORD
int search(int key, struct Record table[])
{
	int i, h, location;
    h = hash(key);				

	location = h;
	for( i=1; i!=MAX-1; i++ )
	{
		if( table[location].status == EMPTY  ) 
			return -1;
		if( table[location].data.id == key)
			return location;
		location = ( h + i*i ) % MAX;								
	}
	return -1;
}
// INSERT RECORD TO TABLE
void insert( struct student stud, struct Record table[] )
{
	int i, location, h;
	
	int key = stud.id;	
	h = hash(key);				
	
	location = h;	
	for(i=1; i!=MAX-1; i++)
	{
		if( table[location].status == EMPTY || table[location].status == DELETED  )
		{
			table[location].data = stud;
			table[location].status = OCCUPIED;	
			printf("Record inserted\n\n");
			return;
		}
		if( table[location].data.id == key )
		{
			printf("Duplicate key\n\n");
			return;
		}
        location = (h+i*i)%MAX;				
	}
	printf("Table overFlow(Record can't be inserted)\n\n");
}
// DISPLAY TABLE
void display(struct Record table[])
{
	int i;
	for(i=0; i<MAX; i++)
	{
		printf("[%d]  : ",i );
		if(table[i].status==OCCUPIED) 
			printf("Occupied : %d   %s  %f\n",table[i].data.id, table[i].data.name, table[i].data.gradepoint);
		else if(table[i].status==DELETED)
			printf("Deleted\n");
		else
			printf("Empty\n");
	}
}
// DELETE RECORD
void del(int key, struct Record table[])
{
	int location = search(key, table);
	if( location == -1 )
		printf("Key not found\n");
	else
		table[location].status = DELETED;
}
// MAIN FUNCTION
int main()
{
	struct Record table[MAX];
	struct student stud;

	int i,key,option;
	
	for( i=0; i<=MAX-1; i++ )
		table[i].status = EMPTY;
		
	while(1)
	{
        printf("\n--------------------------\n");
		printf("1. Insert a record\n2. Search a record\n3. Delete a record\n4. Display table\n5. Exit\nEnter your choice\n");
		scanf("%d",&option);

		switch(option)
		{

			case 1 : 
				printf("Enter id, name, gradepoint  : ");
				scanf("%d %s %f",&stud.id,stud.name,&stud.gradepoint);
				insert(stud, table);
				break;
			case 2 : 
				printf("Enter a key to be searched : ");
				scanf("%d", &key);
				i = search(key, table);
				if( i==-1)
					printf("Key not found\n");
				else
					printf("Key found at index %d\n", i);
				break;
			case 3: 
				printf("Enter a key to be deleted\n");
				scanf("%d",&key);
				del(key, table);
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