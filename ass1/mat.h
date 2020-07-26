/*********************************************************************************************

	header file
	contains some basic array input functions

*********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int complexity = 0;

void input1d (int *a, int n)
{
	
	int i;
	for(i=0; i<n; i++)
		{scanf("%d",(a+i));complexity++;}
	
}

void print1d(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		{printf("%d ",*(a+i));complexity++;}
}	

void input2d ( int a[][10],int *row,int *col)
{
		int i,j;
		printf("number of rows please: ");
		scanf("%d",row);
		printf("number of colms please: ");
		scanf("%d",col);
		puts("Okay now input the elements separated by a space");

		for( i=0; i<*row; i++)
		{
			printf("enter row %d elements: ",i);
			for(j=0; j<*col; j++)
				{scanf("%d",&a[i][j]);complexity++;}
		}

}

void print2d(int a[][10], int row, int col )
{
	int i,j;
	for( i=0; i<row; i++)
		{
			for(j=0; j<col; j++)
				{printf("%d\t",a[i][j]);complexity++;}
			printf("\n");
		}
}
