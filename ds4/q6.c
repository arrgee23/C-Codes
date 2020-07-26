#include<stdio.h>
#include<stdlib.h>

void bubble(int* a,int n);
void selection(int* a,int n);
void insertion(int* a,int n);
void print(int* a,int n);

int main()
{
	printf("Enter the number of elements in array: ");
	int n;
	scanf("%d",&n);
	
	int* a = malloc(n * sizeof(int));
	
	puts("Now enter the elements");
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	puts("***************************   MENU ***********************************");
	puts("1. BUBBLE SORT");
	puts("2. SELECTION SORT");
	puts("3. INSERTION SORT");
	printf("Command: ");
	int k;
	scanf("%d",&k);
	switch(k)
	{
		case 1: bubble(a,n);
		case 2: selection(a,n);
		case 3: insertion(a,n);
	}
}
// increasing order
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
	print(a,n);
}

void print(int *a,int n)
{
	int i;
	printf("The list in ascending order is: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	puts("");
}

void selection(int a[],int n)
{
	int i,j;
	
	for(i=0; i<n-1; i++)
	{
		int min = i; // min remembers the index of minimum number
		
		for(j=i; j<n; j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		//switches them
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	print(a,n);
}

void insertion(int* a,int n)
{
	int i, j, remember;
    for (i = 1; i < n; ++i)
    {
        remember = a[i];
		for (j = i; j > 0 && a[j-1] > remember; j--)
            a[j] = a[j-1];

        a[j] = remember;
    }
	print(a,n);
}

// the end