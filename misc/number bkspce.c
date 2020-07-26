//program that being given an integer input displays the following output
//1st line: all digits, 2nd line:all except 1st digit. etc...
//rahul gautam 19 sep 2012

#include<stdio.h>
main()
{
	int a,count=1,c;
	printf("Enter the num=");
	scanf("%d",&a);
	
	for(c=1;c<=a;c=c*10) //blank loop
	{			        //to determine the largest number suppose x
	                    //that is a power of 10 but
	}                   //smaller than a(input) c=x here(after last execution of the loop)
	//the value of c=x*10 here
	while(c>1) //figure out urself
	{
		printf("Line %d =%d\n",count,a%c);
		c=c/10;    
		count++; //printing no of line
	}
}
