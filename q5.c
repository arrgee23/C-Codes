#include<stdio.h>
#include<stdlib.h>

int  readSet (int *x);
void displaySet (int *x, int n);
void splitter(int *L,int n,int k);

int main(void)
{
	int L[50];
	int n=readSet(L);
	
	//takes input from the user prompts user for input as long as the input is < n
	int k;
	do
	{
		printf("enter value of k: ");
		scanf("%d",&k);
	}
	while(k>n);
	
	splitter(L,n,k);
return 0;	
}

//prints set
void displaySet (int *x, int n)//ok
{
	int i;
	
	for (i=0;i<n;i++)
	{
		printf("%d ",*(x+i));
	}
	puts("");
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

//splits the array into k subarrays according to specified rules

void splitter(int *L,int n,int k)
{
	int R[50][50];
	int i,count=0,j;
	for(i=0; i<k; i++)
	{
		j=i;
		count=0;
		
		while(j<n)
		{
			R[i][count]= *(L+j);
			j=j+k;
			count++;
		}
		printf("subset %d: ",i+1);
		displaySet(R[i],count);
	}
}
