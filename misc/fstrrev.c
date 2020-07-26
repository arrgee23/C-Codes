#include<stdio.h>

void strrev(char a[]) //reverse a given string
{
	int i,length;
	length=strlngth(a);
	
	for(i=length-1;i>=0;i--) //the computer starts counting form 0
	{						//so the serial number of final term = (total terms-1)
		printf("%c",a[i]);
	}
	puts("");
}


main()
{
	char a[30];
	scanf("%s",a);
	strrev(a);
}


int strlngth(char x[]) //this is a very useful function
{
	int i,count=0;
	for(i=0;i<100;i++)
	{
		if(x[i]==0)
		{break;}
		count++;
	}	
	return count;
}