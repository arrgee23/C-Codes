/********************************************************************************************
program that merges two individually sorted array so that after the process of merging the
final array remains sorted...
********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int  readSet (int *x); 
void displaySet (int *x, int n); 
int merger (int *a, int *b,int n1,int n2,int *merg);
int main()
{
    int a[20],b[20],merg[40];

	printf("\nFor array 'A' ");
	int n1 = readSet (a);
	printf("\nFor array 'B' ");
	int n2 = readSet (b);
	int n=merger(a,b,n1,n2,merg);
	puts("THE MERGED ARRAY");
	displaySet(merg,n);

	return 0;
}

int merger (int a[], int b[],int n1,int n2,int sorted[])
{
	int count, i, j;
 
	i = j = 0;
	int sum = n1 + n2;
	for (count = 0; count < sum;) 
	{
		//inputs elements till every element of any subarry is added
		if (i < n1 && j < n2) 
		{
			if (a[i] < b[j]) 
			{
				sorted[count] = a[i];
				i++;
			}
			else 
			{
				sorted[count] = b[j];
				j++;
			}
			count++;
		}
	
		//when every element of arrat 'a' is added it populets the
		//merged array with elements from 'b' array
		else if (i == n1) 
		{
			while(count < sum)
			{
				sorted[count] = b[j];
				j++;
				count++;
			}
		}
	
		else 
		{
			while ( count < sum) 
			{
				sorted[count] = a[i];
				i++;
				count++;
			}
		}
	}
}

//prints set
void displaySet (int x[], int n)//ok
{
	int i;
	puts("");
	for (i=0;i<n;i++)
	{
		printf("%d ",x[i]);
	}
}

//fills up set and returns the number of elements
int  readSet (int *x)
{
		int n,i;
		printf("Give me number of elements of the set: ");
		scanf("%d",&n);

		puts("Okay now input the elements in a sorted manner without repeating");
		for( i=0; i<n; i++)
		{
			scanf("%d",&x[i]);
		}
		return n;
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