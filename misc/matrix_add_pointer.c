#include<stdio.h>
/*The c compiler takes a[2][3] as an array of array a[2][3]~A[3] where A=a[0/1/2]
&s[0]=s ~ s[0]=*s ~ s[1]=*(s+1)s[2][1]=*(s[2]+1)	
as we knw s[2]=*(s+2)
then s[2][1]====*(*(s+2)+1)		
implies s[i][j]==*(*(s+i)+j)*/
int main()
{

	int a[3][3]={{4,23,6},{27,43,0},{2,0,34}};
	int b[3][3]={{2,3,4},{7,3,0},{1,7,4}};
	int i,j;
	puts("**********************************************************\nmatrix addition usin pointers\n**********************************************************");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{
		printf("%d\t",*(*(a+i)+j) + *(*(b+i)+j));	
		}
		puts("");
	}							
}