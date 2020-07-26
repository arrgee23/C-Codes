#include<stdio.h>
int cube(int);
main()
{
int sum=0,n,i=100;
while(i<1000)
	{
		cube(i);
		i++;
	}
}

int cube (int n)
{
int rem,sum=0;
	while(n!=0)
	{
	rem=n%10;
	n=n/10;
	sum=sum+rem*rem*rem;
	}
printf("%d\n",sum);
}
