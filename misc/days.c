#include<stdio.h>
main()
{
	int d,m,y,v=1;
start:	puts("enter date month and year respectively");
	scanf("%d%d%d",&d,&m,&y);
	if(y<1)
	{v=0;}
	if(m<1 || m>12)
	{v=0;}
	if(d<1 || d>31)
	{v=0;}
	
	if (m==9 || m==4 || m==6 || m==11)
	{
		if(d>30)
		v=0;
	}
	
	
if(v==0)
puts("invalid date");
else
puts("valid date");
goto start;
}
