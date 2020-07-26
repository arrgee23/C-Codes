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
	ans=ans/div; //ans means 'vagfol' here.. very poor english
	count++;
}
for(i=0;i<=count-1;i++) //the loop is rotated till (count-1) because the value of count is incremented after the last*
{                       //*execution of the for loop without having any correspondding value of rem[]*
printf("%d",rem[i]);    //this is to avoid printing of garbage value
}
}