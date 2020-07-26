
#include <stdio.h>
main()
{
	
int i,m,n,input,b;

printf("please print a number 2 see the magic\n");
scanf("%d",&input);

for (i=0;i<=input;i++)
	
	{
	if (i<=input/2)
		{
		for(m=0;m<=i;m++)
		printf("*");
		}
	
	else
		{
		for(n=input-i;n>=0;n--)
		printf("*");
		}		
	
	printf("\n");
	}	
}