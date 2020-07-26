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
	// sorts the array
	bubble(a,size);
	
	// searches for an element
	printf("Enter the number u wish to search for: ");
	int n;
	scanf("%d",&n);
	
	if(binarysearch(a,n,10) != -1)
		printf("FOUND!!");
	else
		printf("NOT FOUND!!");
		
	return 0;
}

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
