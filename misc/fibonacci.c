/*This is a program to print the fibonacci series (every number is the sum of previous 2 numbers) upto 10*/
/*In this program a number is initialised with the sum of 0 and 1. Then the values of 0 & 1 is altered 
   & also the value of 0 & sum is altered. This is contained in a loop for 10 times*/

#include<stdio.h>
   int main()
   {
    int i=0,a=0,b=1,c=0; /*We define int type variables and initialize with suitable values*/
     for(i=0;i<10;i++)
      {
       printf(" %d ",c); /*We give spaces for better visibility*/
       c=a+b; /*The sum of 0 & 1 is stored in 'c'*/
       b=a;   /*Then the values of a & b and a & c are altered */
       a=c;
      }
    return 0;
   }

/*This will not take any input and output will be 0 1 1 2 3 5 8 13 21 34*/

