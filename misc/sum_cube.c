#include<stdio.h>
 int main()
  {
   int t=0,rem=0,temp=0,i=0,j=0;
   for(j=1;j<=999;j++)
    {
     t=0;
     i=j;
     while(i>0)
       {
        rem=i%10;               /*This is digit extraction*/
        t=t+(rem*rem*rem);      /*This is cubing the digits and summing it up*/
        i=i/10;
       }
     if(j==t)                   /*Here we check whether the new number matches the old number or not*/
       printf(" %d ",j);
    }
   return 0;
  }
