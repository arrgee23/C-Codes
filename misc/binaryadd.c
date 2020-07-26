#include<stdio.h>
void bin(long a)
{
	int b,r,i=0,c[20],k;
	
	while(a!=0)
	{
		b=a/2;
		r=a%2;
		c[i]=r;
		a=b;
		i++;
	}          //i is incremented once again after the execution of the loop without having any corresponding array value
	printf("Tbinary equivalent is = ");
	for(k=i-1;k>=0;k--) //for the aforesaid reason c[i] has garbage value
   { printf("%d",c[k]); } //so we start printing frm c[i-1]
    puts("\n\n");
}
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
int pow(int k)
{
	int i,a,s=1;
	for(i=0;i<k;i++)
	{
		s=s*2;
	}
	return(s);
}
int converter(char str[],int length)
{
	int condigit[30],i,sum=0,j;
	for(i=0;i<length;i++)
	{
		if(str[i]=='0')
		condigit[i]=0;
		else
		condigit[i]=1;	
	}
	for(i=length-1,j=0;i>=0;i--,j++)
	{
	sum=sum+condigit[i]*pow(j);
	}
	return sum;
}
main()
{
	int length1,length2,digit1,digit2;
	char a[30],b[30]; 
	printf("enter the bigger number=\n");
	scanf("%s",a);
	length1=strlngth(a);
	digit1=converter(a,length1);
	printf("decimalvalue=%d\n\n",digit1);
	
	printf("enter the smaller number=\n");
	scanf("%s",b);
	length2=strlngth(b);
	digit2=converter(b,length2);
	printf("decimal value=%d\n\n",digit2);
	
	printf("the addition is=%d\n",digit1+digit2);
	bin(digit1+digit2);
	
	printf("the subtraction is is=%d\n",digit1-digit2);
	bin(digit1-digit2);
}
