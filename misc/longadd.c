#include<stdio.h>
void converter(char str1[],char str2[]);
void add(void);
void subtract(void);
int strlngth(char x[]);
int a[40],b[40],c[41],d[40],length1,length2;

int main()
{
	int i,choice;
	char x[40],y[40];
	int flag=0;//this is to avoid zeros on the leftmost side if flag=0 then the program wont print
	printf("enter bigger number= ");
	scanf("%s",x);
	printf("\nenter smaller number= ");
	scanf("%s",y);
	length1=strlngth(x);
	length2=strlngth(y);
	converter(x,y);
	printf("tap 1 to add; any other key to subtract: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		add(); //array c[] contains addition results
		puts("The addition is");
		for(i=0;i<=length1;i++)
		{
			if(c[i]==1)
			flag=1;
			if(flag==1)//now the program starts printing
			printf("%d",c[i]);
		}
	}
	else
	{
		subtract(); //array d[] contains subtraction results
		puts("the result is");
		for(i=0;i<length1;i++)
		{
			if(d[i]==1)
			flag=1;
			if(flag==1)//now the program starts printing
			printf("%d",d[i]);
		}
	}
return 0;
}
void converter(char str1[],char str2[])//this function converts char array to int arry
{
	int i;
	for(i=0;i<length1;i++)
	{
		if(str1[i]=='0')
		a[i]=0;
		else
		a[i]=1;	
	}
	for(i=0;i<length1;i++)// make them of same length
	{
		if(i<length1-length2)//this is to make their length equal by making leftmost terms 0 
			b[i]=0;//setting left terms as 0 to make sure they dont contain any garbage value
		else
		{
			if(str2[i-length1+length2]=='0')
			b[i]=0;
			else
			b[i]=1;
		}
	}
}
int strlngth(char x[]) //calculates length of the string
{
	int i,count=0;
	for(i=0;i<100;i++)
	{
		if(x[i]==0)//char x[]is used to take an input of a char array
		{break;}
		count++;
	}
	return count;	
}
void add(void)//adds
{
	int i;
	for(i=0;i<=length1;i++)
	{
		if(a[length1-1-i]+b[length1-1-i]==0)
		{
			c[length1-i]=0;
		}
		if(a[length1-1-i]+b[length1-1-i]==1)//rules of binary addition and subtraction
		{
			c[length1-i]=1;
		}
		if(a[length1-1-i]+b[length1-1-i]==2)
		{
			c[length1-i]=0;
			a[length1-2-i]++;
		}
		if(a[length1-1-i]+b[length1-1-i]==3)
		{
			c[length1-i]=1;
			a[length1-2-i]++;
		}
	}
}
void subtract(void)//subtracts
{
	int i;
	for(i=0;i<length1;i++)
	{
		if(a[length1-1-i]-b[length1-1-i]==0)
		{
			d[length1-i-1]=0;
		}
		if(a[length1-1-i]-b[length1-1-i]==1)
		{
			d[length1-i-1]=1;
		}
		if(a[length1-1-i]-b[length1-1-i]==-1)
		{
			d[length1-i-1]=1;
			a[length1-2-i]--;
		}
		if(a[length1-1-i]-b[length1-1-i]==-2)
		{
			d[length1-i-1]=0;
			a[length1-2-i]--;
		}
	}
}