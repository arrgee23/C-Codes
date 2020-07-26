//Rahul Gautam.. 19 sep 2012//
#include<stdio.h>
main()
{
	int a,b,r=1,v,m,n;
	puts("PROGRAM 2 FIND THE LCM AND GCD OF 2 NUMBERS:\n\n");
	printf("Enter the bigger number=");
	scanf("%d",&a);
	printf("Enter the smaller number=");
	scanf("%d",&b);
	m=a,n=b; //the original value of a and b are not retained in the loop but we need them to calculate the lcm
	if(a%b!=0)
	{
		while(r!=0)
		{
		v=r; //something really intelligent went on here figure out urself	
		r=a%b;
		a=b;
		b=r;
		}
	printf("The GCD is=%d\n",v);
	}
	else
	{
	v=b;
	printf("The GCD is=%d\n",v);
	}
	printf("The LCM is=%d\n",m*n/v);
}
