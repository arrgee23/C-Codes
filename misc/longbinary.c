#include<stdio.h>
int strlngth(char x[]) //char x[]is used to take an input of a char array
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
int pow(int k)//calculates 2^k
{
	int i,a,s=1;
	for(i=0;i<k;i++)
	{
		s=s*2;
	}
	return(s);
}
int converter(char str[],int length)//converts char array to int array and calculates number
{
	int condigit[30],i,j;
	long long int sum=0;
	for(i=0;i<length;i++)//converts char array to int array
	{
		if(str[i]=='0')
		condigit[i]=0;
		else
		condigit[i]=1;	
	}
	
	for(i=length-1,j=0;i>=0;i--,j++)//converts binary to decimal
	{
		sum=sum+condigit[i]*pow(j);
	}
return sum;
}
main()
{
	int length,i;
	long long int digit;// this is to store a bigger number
	char b[30];
	printf("enter the binary number to convert to decimal=\n");
	scanf("%s",b);
	length=strlngth(b);
	digit=converter(b,length);
	printf("The result is= %lld",digit);
}
