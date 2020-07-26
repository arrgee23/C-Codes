#include<stdio.h>
#include "mat.h"



void cathor(int a[],int n1,int b[],int n2);
void catver(int a[],int n1,int b[],int n2);

void display1d ( int *x, int n)
{
    int i;
    for (i=0; i<n; i++)
        {printf("%d ",*(x+i));complexity++;}
    puts("");
}

int read1d ( int *x )
{
    int n,i;
	do
	{
    	printf("give me no of elements: ");
    	scanf("%d",&n);
    	
    }
	while(n < 1 || n > 50);
	puts("Now input elements separated by blank space:");
    for(i=0;i<n;i++)
		{scanf("%d",(x+i));complexity++;}

    return n;
}

void  read2d (int x[][20],int row,int col)
{
	int i,j;
	
	puts("input the elements separated by a space");

	for( i=0; i<row; i++)
	{
		printf("enter row %d elements: ",i);
		
		for(j=0; j<col; j++)
			{scanf("%d",&x[i][j]);complexity++;}
	}

}

void display2d (int a[][20], int rowmax, int colmax)
{
	int i,j;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<colmax;j++)
			{printf("%d ",a[i][j]);complexity++;}
		puts("");
	}
}

int main ()
{
	int a[20],b[20];
	
	int n1 = read1d(a);
	int n2 = read1d(b);
	
	printf("Tap 1 to concat vertically anything else to concat horizontally: ");
	int n;
	scanf("%d",&n);
	
	if(n==1)
		catver(a,n1,b,n2);
	
	else
		cathor(a,n1,b,n2);
	
	printf("\n\nNo of steps taken = %d\n",complexity);
	return 0;
}

void cathor(int a[],int n1,int b[],int n2)
{
	int c[40];
	printf("Tap 1 to keep the first subarray first; anything else to keep the 2nd subarray first: ");
	int n;
	scanf("%d",&n);
	if(n == 1)
	{
		int i,j,count = 0;
		
		for(i=0;i<n1;i++)
		{
			c[count] = a[i];
			count++;
			complexity++;	
		}
		
		for(i=0;i<n2;i++)
		{
			c[count] = b[i];
			count++;
			complexity++;
		}
		display1d(c,count);
	}

	else
	{
		int i,j,count = 0;
		
		for(i=0;i<n1;i++)
		{
			c[count] = b[i];
			count++;	complexity++;
		}
		
		for(i=0;i<n2;i++)
		{
			c[count] = a[i];
			count++;complexity++;
		}
		display1d(c,count);
	}
}

void catver(int a[],int n1,int b[],int n2)
{
	if(n1 != n2)
	{
		puts("Their size must be same");
		exit(1);
	}
	
	else
	{
		int c[20][20],i,j;
		puts("Do you wish to keep array 1 at the top?? press 1 to confrm anything else to deny");
		int n;
		scanf("%d",&n);

		for(i=0;i<n1;i++)

			for(j=0;j<n2;j++)
			{
				if(i==0)
				{	complexity++;
					if(n == 1)
						c[i][j] = a[j];
					else
						c[i][j] = b[j];
				}
				else
				{	complexity++;
					if(n == 1)
						c[i][j] = b[j];
					else
						c[i][j] = a[j];
				}
			}				
		
		display2d (c, n1, n1);
	}
}
