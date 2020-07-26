#include<stdio.h>
//program 2 find digits of a number
main()
{
int ans=1,rem[10],div=10,d,count=0,i;
scanf("%d",&ans);
puts("");
while(ans!=0)
{
	
	rem[count]=ans%div;
	ans=ans/div;
	count++;
	div*=10;
}
for(i=0;i<=count-1;i++)
{
printf("%d",rem[i]);
}
}