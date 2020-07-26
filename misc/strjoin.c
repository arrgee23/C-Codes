#include<stdio.h>
/*this programs joins two strings*/
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

void strjoin (void)
{
	char a[30],b[30],c[60];
	int la,lb,i,j;
	printf("1st string=");
	scanf("%s",a);
	printf("2nd string=");
	scanf("%s",b);
	la=strlngth(a);
	lb=strlngth(b);
	
	for(i=0;i<la;i++) //the length of the joined string will be the total length of bot the strings
	{
		if(i<la)
		c[i]=a[i];
	}
	for(i=0;i<lb;i++)
	{
		c[i+la]=b[i]; //this is to initialise terms in c[] after first few terms has been initialised
	}
	c[i+la]=0;
	printf("%s",c);			//because string inputs
	puts("");
}


main()
{
	strjoin();
}