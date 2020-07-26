/************************************************************************************************
	# C-Program that deletes specified elements from an 1-d array
	# RAHUL GAUTAM
***********************************************************************************************/
#include<stdio.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

//inputs 1d array
void input1d (int *a, int n)
{
	
	int i;
	for(i=0; i<n; i++)
	{
		printf("element %d = ",i+1);
		scanf("%d",(a+i));
	}
}

//prints 1d array
void print1d(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ",*(a+i));
}


void delete(int a[],int n,int *size)
{
    int i;
	*size = *size - 1;complexity++;
	
	for(i=n; i < *size; i++)
	{
		complexity++;complexity++;
		a[i] = a[i+1];
	}
}

int main()
{
    int a[10];
	int size = 10;
    input1d(a,size);
	printf("\nINPUTTED\n");
	
	printf("\nDELETING 3rd and 6th element\n");
	
	//the index of the 3rd element is 2
    delete(a,2,&size);
	printf("\nArray after deletion of 3rd element: ");
    print1d(a,size);
	
	delete(a,5,&size);
	printf("\nArray after deletion of 6th element: ");
    print1d(a,size);
	
	printf("\n\n\nNo of Steps = %d",complexity);
    return 0;
}

