#include<stdio.h>

#define TRUE 1
#define FALSE 0

int * setUnion (int * a, int n1, int *b, int n2, int *n3); 
int * setIntersection (int * a, int n1, int *b, int n2, int *n3);
int  readSet (int *x);
void displaySet (int *x, int n);
int* con (int *a,int *b,int *n);


int main (void)
{
	int a[20],b[20],n2,n3=0,n1;
	int *set;
	
	printf("Reading set 1\n");	
	n1=readSet(a);
	printf("Reading set 2\n");
	n2=readSet(b);
	
	
	printf("The union is:\n");
	set=setUnion (a, n1,b,n2,&n3);
	displaySet( set,n3 );
	puts("");	
	
	printf("The intersectionion is:\n");
	set=setIntersection (a, n1,b,n2,&n3);
	displaySet( set,n3 );
		
	
		
	
return 0;	
}

//prints set
void displaySet (int *x, int n)//ok
{
	int i;
	puts("");
	for (i=0;i<n;i++)
	{
		printf("%d ",*(x+i));
	}
}

//fills up set and returns the number of elements
int  readSet (int *x)
{
		int n,i;
		printf("Give me number of elements of the set: ");
		scanf("%d",&n);
		puts("Okay now input the elements separated by a space");
		for( i=0; i<n; i++)
			scanf("%d",(x+i));
		return n;
}

//calculates union of 2 sets
int * setUnion (int * a, int n1, int *b, int n2, int *n3)
{
	int i,j,count=0;
	static int haha[40];//a static int is declared because we are returning the adress of this array to main
	
	//first it enters the elements of set 1 
	for(i=0; i<n1; i++)
	{
		haha[count]=*(a+i);
		count++;
	}
	
	
	
	for( i=0;i<n2;i++)
	{
		int present = FALSE;		
		//places number if its not present
		for( j=0; j<n1; j++)
			{
				if( *(haha+j)== *(b+i))
					present = TRUE;
			}
		if(present==FALSE)
			{
				haha[count]=*(b+i);
				count++;
			}
	}
	
	*n3=count;
	return haha;
}

int * setIntersection (int * a, int n1, int *b, int n2, int *n3)
{
	int i,j,count=0;
	static int haha[40];
	
	
	for( i=0;i<n2;i++)
	{
		int present = FALSE;		
		//places number if its present
		
		for( j=0; j<n1; j++)
			{
				if( *(a+j)== *(b+i))
					present = TRUE;
			}
		
		if(present==TRUE)
			{
				haha[count]=*(b+i);
				count++;
			}
	}
	
	*n3=count;
	return haha;
}
