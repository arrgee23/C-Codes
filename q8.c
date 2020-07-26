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
void splitter(node** source, int n);

int main(void)
{
	printf("Enter the list\n");
	node* list = read();
	
	int n;
	while(1)
	{
		printf("Enter the number of splits: ");
		scanf("%d",&n);
		if(n<counter(list) && n > 0)
			break;
	}
	
	printf("Master ");display(list);
	splitter(&list , n);
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

void splitter(node** source, int n)
{
	node *slaves[10];
	// creating cursors of slaves
	node *slaveptrs[10];
	int i;
		
	node* cursor = *source;
	int count = 0;
	while(cursor != NULL)
	{
		// saving pointer to the next element of the list
		node* savptr = cursor -> next;
		
		// saving slave base addresses
		if (count < n)
		{
			slaves[count] = cursor;
			slaveptrs[count] = slaves[count];
		}
		else
		{
			slaveptrs[count%n] -> next = cursor;
			slaveptrs[count%n] = slaveptrs[count%n] -> next;
		}
		cursor = savptr;
		count++;
	}
	
	// assigning last nodes next elements as null
	for(i=0;i<n;i++)
		slaveptrs[i] -> next = NULL;

	// displaying lists
	printf("SPLITTED LISTS PRINTING...");
	for(i=0;i<n;i++)
		display(slaves[i]);
}
