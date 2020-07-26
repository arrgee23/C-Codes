#include<stdio.h>
main()
{
	int a,b,c,i,gcd;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=b;i++)
	{
		if(a%i==0 && b%i==0 && c%i==0)
		{gcd=i;}
	}
	printf("%d\n",gcd);
}
