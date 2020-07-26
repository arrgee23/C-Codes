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
void sort(node** set);
int counter(node* first);
node* merger(node* a, node* b);

int main()
{
	puts("Reading a-set....");
	node* aSet = read();
	sort(&aSet);
	display(aSet);
	puts("Reading b-set....");
	node* bSet = read();
	sort(&bSet);
	
	node* merged = merger(aSet,bSet);
	display(merged);
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


// adds a specified integer to  a specified list
void addvalue(node** start, int value)
{
	// making new node
	node* new = malloc(sizeof(node));
	
	// adding value
	new -> n = value;
	
	// linking the node to the list
	new -> next = *start;
	*start = new;
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
/**
 * sorts the list in ascending order
 */
void sort(node** first)
{
	node *ptr;
	int count = counter(*first);
	int i;
	// iterate (number of elements - 1) time
	for(i=0; i<count - 1; i++)
	{
		// uses the logic of bubbble sort
		for(ptr = *first; ptr -> next != NULL ; ptr = ptr -> next)
		{
			node* nextptr = ptr -> next;
			
			if(ptr -> n > nextptr -> n)
			{
				int temp = nextptr -> n;
				nextptr -> n = ptr -> n;
				ptr -> n = temp;
			}
		}
	}
}

node* merger(node* a, node* b)
{
	node* merged = NULL;
	
	// wiring the first node
	if((a -> n) < (b -> n))
	{
		merged = a;
		a = a -> next;
	}
	else
	{
		merged = b;
		b = b -> next;
	}
	
	node* cursor = merged;
	
	// continuing for other nodes
	while(a != NULL && b != NULL)
	{
		if((a -> n) < (b -> n))
		{
			node* saveptr = a -> next;
			cursor -> next = a;
			cursor = a;
			a = saveptr;
		}
		else
		{
			node* saveptr = b -> next;
			cursor -> next = b;
			cursor = b;
			b = saveptr;
		}
	}
	
	if(b == NULL)
	{
		cursor -> next = a;
	}
	else
	{
		cursor -> next = b;
	}
	
	return merged;
}