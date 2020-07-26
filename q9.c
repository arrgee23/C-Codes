#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int n;
	struct node* next;
}node;

// prototypes
node* read(); 
void display(node* aSet);
void addvalue(node** start, int value);
int counter(node* first);
void replicate(node** source, int factor);
void append(node* first, int l);

int main(void)
{
	printf("Enter the list\n");
	node* list = read();
	
	display(list);
	printf("Replication factor please: ");
	int factor;
	scanf("%d",&factor);
	
	replicate(&list,factor);
	display(list);
return 0;
}

// reads a set and returns the pointer to  the set
node* read()
{
	// set a starting point
	node* start = NULL;
	
	printf("Enter numbers enter -1 to exit: ");
	
	while (1)
	{
		
		int num;
		scanf("%d",&num);
		
		if(num == -1)
			break;
			
		node* new = malloc(sizeof(node));
		new ->n = num;
		// prepending the node
		new -> next = start;
		start = new;
	}
	
	return start;
}

void display(node* aSet)
{
	printf("List is: ");
	while(aSet != NULL)
	{
		printf("%d ",aSet -> n);
		aSet = aSet -> next;
	}
	puts("\n");
}

/**
 * returns the number of elements in the list
 */
int counter(node* first)
{
	node* ptr = first;
	int count = 0;
	while(ptr != NULL)
	{
		ptr = ptr -> next;
		count++;
	}
	return count;
}

void replicate(node** source, int factor)
{
	int i,j;
	node* cursor;
	int nodecount = counter(*source);
	for(i=0; i<factor; i++)
	{
		for(j=0,cursor = *source; j < nodecount; j++,cursor = cursor -> next)
		{
			append(*source,cursor -> n);
		}
	}
}


/**
 * appends a number in the list
 */
void append(node* first, int l)
{
	// try to instantiate node for number
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
        return;

    // initialize node
    newptr->n = l;
	newptr -> next = NULL;
	
	// insetring it at the correct place
	node* cursor = first;
	
	// finding the last elemnt
	while(cursor -> next != NULL)
		cursor = cursor -> next;
		
	// making the last element to point to the newly created node
	cursor -> next = newptr;
}