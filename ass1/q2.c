/*********************************************************************************************************************************
	* Program that multiplies 2 matrices
*********************************************************************************************************************************/
#include "mat.h"



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
		printf("Matrices with entered orders can't be multiplied with each other.\n");
  
	else
	{
		for ( c=0; c<row1; c++ )
		{
			for ( d=0; d<col2; d++ )
			{
				for ( k= 0; k<row2 ; k++ )
				{
					sum = sum + a[c][k] * b[k][d];
					complexity++;
				}

				multiply[c][d] = sum;
				sum = 0;
			}
		}

		printf("Product of entered matrices:-\n");

		print2d(multiply,row1,col2);
	}

	printf("\n\nNo of steps taken = %d\n",complexity);
	return 0;
}
