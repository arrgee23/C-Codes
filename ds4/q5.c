#include<stdio.h>
#include<stdlib.h>

void search(int* a,int n);

int main()
{
	printf("Enter the number of elements in array: ");
	int n;
	scanf("%d",&n);
	
	int* a = malloc(n * sizeof(int));
	
	puts("Now enter the elements:");
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	// searches for an element
	printf("Enter the number u wish to search for: ");
	scanf("%d",&n);
	search(a,n);
}

void search(int* a,int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(a[i] == n)
		{
			printf("FOUND!!");
			exit(0);
		}
	}
	printf("NOT FOUND!!!");
}