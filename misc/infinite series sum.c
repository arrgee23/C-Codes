#include<stdio.h>
main()
{
	float j,a,i,c=0;
	printf("input a number 2 see the series sum..\n");
	scanf("%f",&j);
	printf("thanks 4 ur input\n the series is...\n\n");
	
	for(i=1;i<=j;i++)
	{
		a=1/i;
		c=c+a;
		if(i<j)
		printf("(1/%2.0f)+",i);
		else
		printf(" (1/%2.0f) ",i);
	}
	printf("\n\nand the sum is = %f\n",c);
	
}