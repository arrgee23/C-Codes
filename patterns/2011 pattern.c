#include<stdio.h>
main()
{
	int i,j,k,l,m,n=9,count=1;
	printf("input the number of lines=\n");

	
	for(i=n;i>=1;i--)
	{
		for(j=i;j>=1;j--)
		{printf("%d",j);}
		
		if(i!=n)
		{
			for(k=1;k<=count;k++)
			{printf(" ");}
			count=count+2;
		}
		
		for(k=1;k<=i;k++)
		{printf("%d",k);
		if(i==n && k==1)
		printf("\b");
		}
		
		puts("");
	}
}
