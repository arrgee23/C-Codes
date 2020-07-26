#include<stdio.h>
#include<stdlib.h>

void m_sort(int numbers[], int temp[], int left, int right);
void print(int *a,int n);
void quicksort(int x[],int first,int last);

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
		
	quicksort(a, 0, size - 1);
	print(a,size);
	return 0;
}

void print(int *a,int n)
{
	int i;
	printf("The list in ascending order is: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	puts("");
}

void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;
         
         while(i<j)
         {
             while(x[i] <= x[pivot] && i < last)
                 i++;
             while(x[j] > x[pivot])
                 j--;
             
             if(i < j)
             {
                 temp = x[i];
                  x[i] = x[j];
                  x[j] = temp;
             }
             //print(x,5);
         }

         temp = x[pivot];
         x[pivot] = x[j];
         x[j] = temp;
        // print(x,5);
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
