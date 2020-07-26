/*
BUBBLE SORT
*sorts an array by comparing each memer to the next member and if desired then switching their place
*stops execution when no changes are made
 */
#include<stdio.h>
int main()
{
	int a[100],n,i,j,k,change=1,count=0;
	printf("Hw many numbs d u wnt 2 sort? ");
	scanf("%d",&n);
	printf("Okay nw enter them separated by a space:\n");
	
	for(i=0;i<n;i++)	//scanning numbs
		scanf("%d",&a[i]);
	
	while(change!=0)
	{
		count++;
		change=0;
		for(i=0;i<n-1;i++)//i<n-1 is written insted of i<n because the nth term contains garbage value
		{
			if(a[i]<a[i+1]) //this is what i ws talkin abt 
			{
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
				change=1;
			}
		}
		printf("Iteration %d: ",count);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);//printing changed value aftr each iteration
		puts("");
	}
	printf("\nFinal value: ");
	for(i=0;i<n;i++)//printing final value
		printf("%d ",a[i]);
	puts("");
	return 0;
}
