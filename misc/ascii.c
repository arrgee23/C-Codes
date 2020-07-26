#include<stdio.h>
main()
{
	char A;	int i;
	A=0;
	puts("List of ASCII values:");
	for(i=0;i<=200;i++)
	{
		printf("%c = %d\n",A+i,A+i);
	}
	getch();
}
