//program that reads a float point number
//and displays the rightmost num of int part
//19 sep 2012 Rahul Gautam

#include<stdio.h>
main()
{
	float a;
	puts("input the float value");
	scanf("%f",&a); //taking input
	int k;
	k=(int)a; //note how typecast is used to store the integer
	          //part of the float number in a variable
	printf("%d\n",k%10);          
}
