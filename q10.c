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
void RemoveAllBut(node** list,int n);

int main(void)
{
	printf("Enter the list\n");
	node* list = read();
	display(list);
	
	printf("Enter the number to keep: ");
	int n;
	scanf("%d",&n);
	
	RemoveAllBut(&list,n);
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
	printf("List now: ");
	while(aSet != NULL)
	{
		printf("%d ",aSet -> n);
		aSet = aSet -> next;
	}
	puts("\n");
}

void RemoveAllBut(node** list,int n)
{
	node* cursor;
	for(cursor = *list; cursor != NULL; cursor = cursor -> next)
	{
		if(cursor -> n == n)
		{
			(*list) = cursor;
			(*list) -> next = NULL;
		}
	}
}