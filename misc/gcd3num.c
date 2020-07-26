#include<stdio.h>
int hcf(int,int);
main()
{
	int a,b,c,lcm,gcd;
	printf("Enter number 1 :");
	scanf("%d",&a);
	printf("Enter number 2 :");
	scanf("%d",&b);
	printf("Enter number 3 :");
	scanf("%d",&c);
	gcd=hcf(a,b);
	lcm=a*b/gcd;
	gcd=hcf(c,gcd);
	lcm=lcm*c/gcd;
	printf("The lcm is=%d\nthe gcd is=%d\n",lcm,gcd);
}

int hcf(int a, int b)
{
	int r=1,v;
		if(a%b!=0)
	{
		while(r!=0)
		{
		v=r; //something really intelligent went on here figure out urself	
		r=a%b;
		a=b;
		b=r;
		}
	}
	else
	{
	v=b;
	}
	return(v);
}
