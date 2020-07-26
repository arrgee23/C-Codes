#include<stdio.h>
main()
{
	int k,n;
	puts("input a number");
	scanf("%d",&n);
	k=n%2;
	switch(k)
	{
	case 1: puts("the number is odd");break;
	case 0: puts("the number is even");break;
	}
}