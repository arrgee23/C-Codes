#include<stdio.h>

int bigger (int a, int b);
void readSet (int x[][50],int *rowmax,int *colmax);
int rowcheck(int x[][50],int *rowmax,int *colmax);
int colmcheck(int x[][50],int *rowmax,int *colmax);
int diagonalcheck(int x[][50],int *rowmax,int *colmax);
void rowmajor (int a[][50], int rowmax, int colmax);


int main(void)
{
	int a[50][50],rowmax,colmax,r,c,d,biggest;
	readSet (a,&rowmax,&colmax);
	
	r= rowcheck(a,&rowmax,&colmax);
	c= colcheck(a,&rowmax,&colmax);
	d= diagonalcheck(a,&rowmax,&colmax);
	
	biggest=bigger(r,c);
	biggest=bigger(biggest,d);
	
	printf("Inputted matrix in row major form:\n");
	rowmajor (a, rowmax,colmax);
	
	printf("\n\nThe biggest line segment is: %d",biggest);
return 0;
}

void  readSet (int x[][50],int *rowmax,int *colmax)
{
		int row,col,i,j;
		printf("Give me number of rows of the set: ");
		scanf("%d",&row);
		printf("Give me number of colms of the set: ");
		scanf("%d",&col);
		puts("Okay now input the elements separated by a space");

		for( i=0; i<row; i++)
		{
			printf("enter row %d elements: ",i);
			for(j=0; j<col; j++)
				scanf("%d",&x[i][j]);
		}

		*rowmax=row;
		*colmax=col;

}



int  diagonalcheck(int x[][50],int *rowmax,int *colmax)
{
int row=0,col=0,i,j,count=0,tempcount=0,maxcount=0;



	//accesses elements diagonally
	if(row==0)
	{
		while(col<*colmax)
		{
			int r=row;int c=col;
			
			count=0;
			
			while(r<*rowmax && c<*colmax)
			{
				//print	
				
				if( x[r][c]==1 )
					count++;

				else if( x[r][c]==0 )
				{
					if( count > tempcount )
					tempcount=count;
					count=0;
				}
					r++;
					c++;
			}
				//puts("");
				col++;
			
				if( tempcount > maxcount && tempcount > count )
					maxcount = tempcount;
				if( count > maxcount && count > tempcount )
					maxcount = count;
			
		
		}
		row++;
	}
	while(row<*rowmax)
	{
		col=0;
		int r=row;int c=col;
		count=0;
		while(r<*rowmax && c<*colmax)
		{
			//printf("%d ",a[r][c]);
			
				if( x[r][c]==1 )
				count++;

			else if( x[r][c]==0 )
			{
				if( count > tempcount )
				tempcount=count;
				count=0;
			}
			
			r++;
			c++;
		}
		//puts("");
		
		if( tempcount > maxcount && tempcount > count )
				maxcount = tempcount;
			if( count > maxcount && count > tempcount )
				maxcount = count;
		
		row++;
	}
	return maxcount;
}
			


//checks rows and returns the maximum number of adjacent 1 s
int rowcheck(int x[][50],int *rowmax,int *colmax)
{
	int i,j,count=0,tempcount=0,maxcount=0;
	for(i=0; i<*rowmax;i++)
	{
		count = 0;
		
		for(j=0; j<*colmax; j++)
		{
			if( x[i][j]==1 )
				count++;

			else if( x[i][j]==0 )		//figure out urself
			{
				if( count > tempcount )
				tempcount=count;
				count=0;
			}

		}

		if( tempcount > maxcount && tempcount > count )
				maxcount = tempcount;
			if( count > maxcount && count > tempcount )
				maxcount = count;
	}
	return maxcount;
}

int colcheck(int x[][50],int *rowmax,int *colmax)
{
	int i,j,count=0,tempcount=0,maxcount=0;
	for(i=0; i<*rowmax;i++)
	{
		count = 0;
		for(j=0; j<*colmax; j++)
		{
			

			if( x[j][i]==1 )
				count++;

			else if( x[j][i]==0 )
			{
				if ( count > tempcount )
					tempcount=count;
				count=0;
			}

		}

		if( tempcount > maxcount && tempcount > count )
				maxcount = tempcount;
			if( count > maxcount && count > tempcount )
				maxcount = count;
	}
	return maxcount;
}

int bigger (int a, int b)
{
	if(a>b)
		return a;
	else
		return b;

}

void rowmajor (int a[][50], int rowmax, int colmax)
{
	int i,j;
	
	for(i=0;i<rowmax;i++)
		for(j=0;j<colmax;j++)
			printf("%d ",a[i][j]);

}