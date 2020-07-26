//19 sep 2012 "greatest pattern printing" rahul gautam

#include <stdio.h>
int main()
{

int i,j,k,l,m,n,o;
puts("Enter the number of rows");
scanf("%d",&n);

if(n%2==0)
{o=n/2;} //determining the midpoint & assigning its value 2 o
else
{o=(n+1)/2;} 

for(i=1;i<=n;i++)
	{
	if(i<=o) //printing upper triangle
		
		{
		for(j=1;j<=o-i;j++)
			{
			printf(" ");  //printing blank spaces
			}
		for(k=1;k<=2*i-1;k++)
			{
			printf("%d",i);  //printing numbers
			}
		}
		
	else  // printing lower triangle
		{
		
		if(n%2==0) //the number of blank space is different for
		{            //odd & evern value of n
			for(l=1;l<=i-1-o;l++)
			{printf(" ");}
		}
		else                  //printing blank space
		{
			for(l=1;l<=i-o;l++)
			{printf(" ");}
		}
		
		for(m=1; m<=2*n+1-2*i; m++)
			
		{printf("%d",2*o-i+1);}  //priting lower triangle digits
		}
	printf("\n");	//this is the most important line
	}
	getchar();
	return 0;
}
