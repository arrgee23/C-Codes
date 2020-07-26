#include<stdio.h>
#include<conio.h>

main()
{   
	int n,r,c,i,comb=1,j;
	printf("enter two numbers in ncr form to see their combination\n");
	printf("enter n=");
	scanf("%d",&n);
	printf("enter r=");
	scanf("%d",&r);

	for(i=1;i<=r;i++)
	{
		comb=comb*n;  //(n)(n-1)(n-2)...(n-r)=comb//
		n--;
	}
	for(j=1;j<=r;j++)
	{
		comb=comb/j; //comb/r!//
	}
	printf("%dC%d=%d\n",n,r,comb);
}
