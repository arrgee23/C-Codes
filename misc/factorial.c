#include<stdio.h>
main()
{
	int a,b=1,i;
	printf("enter a number to show its factorial =");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		b=b*i;
		
	}
	printf("\nThe factorial is=%d\n",b);
	getchar();
}
