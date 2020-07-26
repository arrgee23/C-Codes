/*********************************************************************************************************************************
	* Program that multiplies 2 matrices
	# RAHUL GAUTAM
*********************************************************************************************************************************/
#include <stdio.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

//inputs 2d array
void input2d ( int a[][10],int *row,int *col)
{
		int i,j;
		printf("number of rows please: ");
		do
		{
			scanf("%d",row);
		}
		while(*row <= 0 || *row > 10);
		printf("number of colms please: ");
		do
		{
			scanf("%d",col);
		}
		while(*col <= 0 || *col > 10);
		puts("Okay now input the elements separated by a space");

		for( i=0; i<*row; i++)
		{
			printf("enter row %d elements: ",i);
			for(j=0; j<*col; j++)
				scanf("%d",&a[i][j]);
		}

}

void print2d(int a[][10], int row, int col )
{
	int i,j;
	for( i=0; i<row; i++)
		{
			for(j=0; j<col; j++)
				printf("%d\t",a[i][j]);
				puts("");
		}
}

int main()
{
	puts("\n\n\t\t****C-program that multiplies two matrices****\n\n\tMake sure No. of cols of 1st matrix = No. of rows of 2nd matrix\n\n");
	puts("MATRIX 1");
	int a[10][10];
	int row1,col1;
	input2d(a,&row1,&col1);
	
	puts("MATRIX 2");
	int b[10][10];
	int row2,col2;
	input2d(b,&row2,&col2);
	
	int c, d, k, sum = 0;
	int multiply[10][10];
	
	//process of multiplication begins
	if ( col1 != row2 )
	{	
		complexity++;
		printf("Matrices with entered orders can't be multiplied with each other.\n");
		puts("\n\nDONT SAY I DIDNT WARN YOU!!!");
		return 1;
	}
		
	else
	{
		for ( c=0; c<row1; c++ )
		{
			for ( d=0; d<col2; d++ )
			{
				for ( k= 0; k<row2 ; k++ )
				{
					sum = sum + a[c][k] * b[k][d];
					complexity++;;
				}
				complexity++;
				multiply[c][d] = sum;
				sum = 0;
			}
		}

		printf("\nProduct of entered matrices:-\n");

		print2d(multiply,row1,col2);
	}

	printf("\n\n\nNo of Steps = %d",complexity);
	return 0;
}