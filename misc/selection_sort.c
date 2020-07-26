/*
*	SELECTION SORT
* 	program will work its way from left to right and keep track of the smallest number
	encounterd on each iteration through the numbers. On the first iteration of 
	the loop,if we find that the number n is the smallest. We then swap n with the 
	number at the front of the list. 

*	 n^2 iterations everytime not efficient
*/
#include<stdio.h>
int main()
{
	int a[100],n,i,j,temp,change=1,count=0;
	printf("Hw many numbs d u wnt 2 sort? ");
	scanf("%d",&n);
	printf("Okay nw enter them separated by a space:\n");
	
	for(i=0;i<n;i++)	//scanning numbs
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			
		}
	}
