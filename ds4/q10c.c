#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node* next;
}node;

int hash(int value);
void prepend(node** first,int n);
void printlist(node* first);

int main()
{
	FILE* fp = fopen("NumberGen_4_digit.txt" , "r");
	node* cache[100] = {NULL};
	
	int chain_length[100] = {0};
	
	int temp;
	while(fscanf(fp,"%d",&temp) == 1)
	{
		prepend( (&cache[hash(temp)]) , temp );
		chain_length[hash(temp)]++;
	}
	fclose(fp);
	
	int i;
	int sum = 0;
	for(i=0;i<100;i++)
	{	
		printf("cache[%d] > ",i);printlist(cache[i]); puts("");
		sum = sum + chain_length[i];
	}
	
	printf("\n\n Avg chain length = %f",sum/100.0);
	
	return 0;
}

int hash(int value)
{
	if(value < 10)
		return value;
	else
		return value / 100;
}

void prepend(node** first,int n)
{
	if(first == NULL)
	{
		node* new = malloc(sizeof(node));
		new -> next = NULL;
		
		new -> value = n;
		*first = new;
	}
	else
	{
		node* new = malloc(sizeof(node));
		new -> value = n;
		new -> next = *first;
		*first = new;
	}
}

void printlist(node* first)
{
	node* cursor;
	for(cursor = first; cursor != NULL; cursor = cursor -> next)
		printf("%d ",cursor -> value);
}
