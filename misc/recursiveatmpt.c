#include<stdio.h>

int add (int n) //adds a numbr 3...3+2+1, 4..4+3+2+1 
{
int s=0;
printf("befor loop n=%d\n",n);
if(n>1)
n=n+add(n-1);
printf("aftrr loop n=%d\n",n);
return n;
}

int ladd(int n)
{
int s=0;
s=s+add(n);
n--;
return s;	
}

int main()
{
int n,x;
scanf("%d",&n);
x=ladd(n);
printf("%d\n",x);
return 0;
}
