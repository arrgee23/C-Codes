#include<stdio.h>
#include"cs50.h"
int main (void)
{
int height,i,j,k;
printf("Eneter the height smaller than 23:");
height = GetInt();
while(height<0 || height>23)
	{
		printf("Invalid input, input a smaller/non negative value\n");
		printf("Height:");
		height = GetInt();
	}
	for(i=0;i<height;i++)
	{
		for(j=0;j<height-1-i;j++)
		{
			printf(" ");
		}
		for(k=0;k<i+2;k++)
		{
			printf("#");
		}
		printf("\n");
	}
}
