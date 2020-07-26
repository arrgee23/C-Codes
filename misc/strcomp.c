/*this program compares two strings to check if they are same.. 
the function strcomp can be used afterwrds but be carefful.. a it uses
the function strlength so they should be copied together*/

#include<stdio.h>
int strcomp(char x[],char y[])
{
	int i,lsx,lsy,flag=1; //lsa=length of string a
	lsx=strlngth(x); //calculation of string length
	lsy=strlngth(y);
	if(lsx!=lsy) //
	{
		printf("They dont even have same number of letters\n");
		flag=0;
	}
	else
	{
		for(i=0;i<lsx;i++)
		{	
			printf("comparing letter %d %c-%c",i+1,x[i],y[i]);//to add some drama effect
			if(x[i]!=y[i])
			{
			flag=0;
			puts("\t-doesnt match");
			}
			else
			puts("\t-match");
		}
	}
return flag;
}

int strlngth(char x[])
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

int main()
{
	char a[30],b[30];
	int i,t;
	printf("enter word 1="); 
	scanf("%s",&a);
	printf("enter word 2=");
	scanf("%s",&b);
	t=strcomp(a,b);
	if(t==1)
	printf("\n\nthey are same\n");
	else
	printf("\n\nthey are different\n");
}