/************************************************************************************************
	# C-Program that
		* Tests if a matrix is symmetric
		* Saves memory by storing common elements
		  in 1-d array.
		* Calculates sums of individual columns.
	# RAHUL GAUTAM
***********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

//prints 1d array
void print1d(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ",*(a+i));
}	

void inputmat ( int a[][10],int n)
{
	int i,j;
	puts("Okay now input the elements of the symmetric mztrix separated by a space");

	for( i=0; i<n; i++)
	{
		printf("enter row %d elements: ",i);
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	}
	
	//testing if the matrix is symmetrc
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			complexity++;complexity++;
			complexity++;
			if(a[i][j] != a[j][i])
			{
				printf("The matrix is not symmetric");
				exit(1);
			}
		}
}
int main()
{
	printf("Enter order of the square matrix: ");
	int n;
	do
	{
		scanf("%d",&n);
	}
	while(n <= 0 || n > 10);
	int matrix[10][10];
	inputmat (matrix,n);
	
	int *arr = malloc( n*(n+1)/2 * sizeof(int) ); //n*(n+1)/2 is the total no. of unique elements
	
	//inputting elements in 1d array
	int count=0,i,j;
	for(i=0;i<n;i++)
		for(j=i; j<n; j++)
		{ 
			complexity++;complexity++;
			arr[count] = matrix[i][j]; 
			count++;
		}
			
	printf("MATRIX stored in 1d array as: ");
	print1d(arr,count);
	puts("");
		
	//addition result of individual columns
	
	for(i=0;i<n;i++)
	{
		complexity++;complexity++;
		int sum = 0;
		for(j=0;j<n;j++)
			{sum = sum + matrix[j][i];complexity++;complexity++;}
		printf("sum of column %d = %d\n",i+1,sum);
	}
	printf("\n\n\nNo of Steps = %d",complexity);
return 0;
}

