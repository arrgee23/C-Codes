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
node* setUnion(node* firstSet, node* secondSet);
node* setIntersection(node* firstSet, node* secondSet);
void addvalue(node** start, int value);

int main(void)
{
	puts("Reading a-set....");
	node* aSet = read();
	//display(aSet);
	
	puts("Reading b-set....");
	node* bSet = read();
	//display(bSet);
	
	node* intersection = setIntersection(aSet,bSet);
	printf("INTERSECTION ");display(intersection);
	
	node* sunion = setUnion(aSet,bSet);
	printf("unION ");display(sunion);
	
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

node* setIntersection(node* firstSet, node* secondSet)
{
	node* start = NULL;
	node* temp = secondSet;
	while(firstSet != NULL)
	{	
		secondSet = temp;
		while(secondSet != NULL)
		{
			
			if(secondSet -> n == firstSet -> n)
			{
				addvalue(&start,firstSet -> n);  // adds  the value to a specific linked list
			}
			secondSet = secondSet -> next;
		}
		firstSet = firstSet -> next;
	}
	return start;
}


// adds a specified integer to  a specified list
void addvalue(node** start, int value)
{
	// making new node
	node* new = malloc(sizeof(node));
	
	// adding value
	new -> n = value;
	
	// prepending the node
	new -> next = *start;
	*start = new;
}

node* setUnion(node* firstSet, node* secondSet)
{
	node* start = NULL;
	node* temp = secondSet;
	
	while(firstSet != NULL)
	{	
		bool present = false;
		secondSet = temp;
		while(secondSet != NULL)
		{
			
			if(secondSet -> n == firstSet -> n)
			{  
				present = true;
				break;
			}
			secondSet = secondSet -> next;
		}
		
		if(present == false)
		{
			addvalue(&start,firstSet -> n);  // adds  the value to a specific linked list	
		}
		firstSet = firstSet -> next;
	}
	
	while(temp != NULL)
	{
		addvalue(&start,temp -> n);
		temp = temp -> next;
	}
	return start;
}