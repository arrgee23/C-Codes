#include<stdio.h>
main()
{
	int i,j,k,l,m=0;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{

			for(k=1;k<=4;k++)
			{	
				for(l=1;l<=4;l++)
				{
				printf("%d%d%d%d\n",i,j,k,l);
				m=m+1;
				}
				
			}
			
		}
		
	}
	printf("the total number of combinations=%d",m);
}
