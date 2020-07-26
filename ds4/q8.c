#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int binarysearch(int* a,int n,int size);
void bubble(int* a,int n);

int main()
{
	printf("Enter the number of elements in array: ");
	int size;
	scanf("%d",&size);
	
	int* a = malloc(size * sizeof(int));
	
	puts("Now enter the elements:");
	int i;
	for(i=0; i<size; i++)
	{
		scanf("%d",&a[i]);
	}
	
	// stores the last searched element
	int temp = -1;
	int counter = 0;
	
	// sorts the array
	bubble(a,size);
	
	int choice;
	do
	{
		// searches for an element
		printf("Enter the number u wish to search for: ");
		int n;
		scanf("%d",&n);
		
		if(counter == 0)
		{
			temp = binarysearch(a,n,10);
			
			if(temp != -1)
				printf("FOUND!!");
			else
				printf("NOT FOUND!!");
			
			counter = 1;
		}
		else
		{
			if(a[temp] == n)
				printf("FOUND!!");
			else
			{
				temp = binarysearch(a,n,10);
			
				if(temp != -1)
					printf("FOUND!!");
				else
					printf("NOT FOUND!!");
			}
		}
		
		
		printf("Do you wish to search for another value?(1/0)");
		scanf("%d",&choice);
	}while(choice == 1);
		
	return 0;
}

// for sorting the list
void bubble(int *a,int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j < n-1-i; j++) // with every pass the biggest number is bubbled at the end of the list thus (n-1-i)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int binarysearch(int* a,int n,int size)
{
	int head = 0;
	int tail = size -1;
	int mid;
	
	for(mid = (head + tail)/2; head <= tail; mid = (head + tail)/2)
	{
		if(a[mid] == n)
			return mid;
		
		if(n > a[mid])
			head = mid + 1;
		else
			tail = mid -1;
	}
	return -1;
}