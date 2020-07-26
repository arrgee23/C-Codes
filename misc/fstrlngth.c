/*function calculates length of string
every string ends with a null character; ascii value of 0
this property is used in calculating the length of the string*/

#include<stdio.h>

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
//copy the above function to calculate the length of a string
int main()
{
char a[30];
int length;
scanf("%s",&a);
length=strlngth(a);
printf("The length of the string is=%d\n",length);
}