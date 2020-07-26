/****************************************************************************
	*SPARSE MATRIX MANIPULATION
	*CHECKS IF A MATRIX IS SPARSE
	*GIVES SPARSE REPRESENTATION
	*ADDS TWO SPARSE MATRICES
	*MULTIPLIES TWO SPARSE MATRICES
	# RAHUL GAUTAM
****************************************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

void rep_sparse(int a[][10], int row, int col);
bool ifsparse(int a[][10], int row, int col);
void add(int a[][10], int row, int col,int b[][10],int c[][10]);
void mul(int a[][10],int row,int col1,int b[][10],int row2,int col2);

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

//prints 2d array
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

struct sparse
{
	int row;
	int col;
	int value;
};

int main()
{
	//for matrix 1 checking if its a sparse matrix and giving the sparse representation
	int a[10][10];
	int rowno,colno;;
	input2d(a,&rowno,&colno);
	
	if(ifsparse(a,rowno,colno))
	{
		rep_sparse(a,rowno,colno);
	}
	else
		puts("The matrix is not sparse");
	
	//matrix 2	
	int b[10][10];
	int rowno2,colno2;
	input2d(b,&rowno2,&colno2);
	
	complexity++;
	if(ifsparse(b,rowno2,colno2))
	{
		rep_sparse(b,rowno2,colno2);
	}
	else
		puts("The matrix is not sparse");
		
	//calculating their addition
	complexity++;
	if(rowno == rowno2 && colno == colno2)
	{
		int c[10][10];
		//calculates their addition and stores in c
		add(a,rowno,colno,b,c);
	}
	else
		printf("\nMatrix addition not possible");
		
	//calculating their multiplication	
	mul(a,rowno,colno,b,rowno2,colno2);
	printf("\n\n\nNo of Steps = %d",complexity);
return 0;
}

//checks if a given matrix is sparse
bool ifsparse(int a[][10], int row, int col)
{
	int i,j,count =0;
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			complexity++;
			
			complexity++;
			if(a[i][j] == 0)
				count++;
		}
	
	complexity++;
	if( row*col / (float)count <= 2)
		return true;
	else
		return false;
}

//produces the sparse representation
void rep_sparse(int a[][10], int row, int col)
{
	int i,j,count =0;
	struct sparse kol[100];
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			complexity++;
			complexity++;
			if(a[i][j] != 0)
			{
				kol[count].row = i;
				kol[count].col = j;
				kol[count].value = a[i][j];
				count++;
			}
				
		}
	printf("Sparse representation:\n");
	printf("ROW\tCOL\tVALUE\n");
	for(i=0;i<count;i++)
		printf("%d\t%d\t%d\n",kol[i].row,kol[i].col,kol[i].value);
}

//adds two matrices
void add(int a[][10], int row, int col,int b[][10],int c[][10])
{
	int i,j;
	for(i = 0; i < row; i++)
		for(j=0; j<col; j++)
			{c[i][j] = a[i][j] + b[i][j];complexity++;}
			
	printf("\n\n ADDITION: \n\n");		
	print2d(c,row,col);
}

//multiplies two matrices
void mul(int a[][10],int row1,int col1,int b[][10],int row2,int col2)
{
	int c, d, k, sum = 0;
	int multiply[10][10];
	
	//process of multiplication begins
	if ( col1 != row2 )
	{	
		printf("Matrices with entered orders can't be multiplied with each other.\n");
		exit(1);
    }
	else
	{
		for ( c=0; c<row1; c++ )
		{
			for ( d=0; d<col2; d++ )
			{
				for ( k= 0; k<row2 ; k++ )
				{
					complexity++;
					sum = sum + a[c][k] * b[k][d];
				}
				
				complexity++;
				multiply[c][d] = sum;
				sum = 0;
			}
		}

		printf("\n\nProduct of entered matrices:-\n\n");

		print2d(multiply,row1,col2);
	}
}