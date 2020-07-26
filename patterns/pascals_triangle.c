/*Rahul Gautam combination triangle*/
/*28 sep 2012*/

#include<stdio.h>

int combination (int,int); //prototype declaration just to remind the main function that it has other program
main()
{
	int n,i,j,k,a;
	puts("enter no. of lines:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=1;j<=n-1-i;j++)
		{printf("\t");}
		
		for(k=0;k<=i;k++)
		{
			a=combination(i,k);//
			printf("\t%d\t",a); //an xtra blank space is printed*
		}                    //*just 2 prnt t pattern crectly*
		puts("");            //*cn xpriment by dletin blank spce
	}	

}
//function combination//

int combination (int n,int r)
{
	int comb=1,i,j;	//Blah blah figure out urself
	for(i=1;i<=r;i++)
	{
		comb=comb*n;
		n--;
	}
	for(j=1;j<=r;j++)
	{
		comb=comb/j;
	}
return comb;	
}
