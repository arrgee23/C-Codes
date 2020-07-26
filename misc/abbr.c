/*abbreviate a given string Rahul Gautam=R.G*/
#include<stdio.h>
int main()
{
	char name[50];
	int i=0;
	gets(name);
	printf("%c.",name[0]-32);
	while(name[i]!=0)
	{
		if(name[i]==' ')
		{
			printf("%c.",name[i+1]-32);
		
		}
		i++;
	}
	return 0;
}