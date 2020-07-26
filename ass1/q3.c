#include "mat.h"



void rep_sparse(int a[][10], int row, int col);
bool ifsparse(int a[][10], int row, int col);
void add(int a[][10], int row, int col,int b[][10],int c[][10]);
void mul(int a[][10],int row,int col1,int b[][10],int row2,int col2);

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
	
	if(ifsparse(b,rowno2,colno2))
	{
		complexity++;
		rep_sparse(b,rowno2,colno2);
	}
	else
		puts("The matrix is not sparse");
		
	//calculating their addition
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

	printf("\n\nNo of steps taken = %d\n",complexity);
return 0;
}

//checks if a given matrix is sparse
bool ifsparse(int a[][10], int row, int col)
{
	int i,j,count =0;
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(a[i][j] == 0)
				count++;complexity++;
		}
	
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
			if(a[i][j] != 0)
			{
				kol[count].row = i;
				kol[count].col = j;
				kol[count].value = a[i][j];
				count++;complexity++;
			}
				
		}
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
	printf("\n ADDITION: \n");		
	print2d(c,row,col);
}

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
					sum = sum + a[c][k] * b[k][d];
				}

				multiply[c][d] = sum;
				sum = 0;
			}
		}

		printf("Product of entered matrices:-\n");

		print2d(multiply,row1,col2);
	}
}
