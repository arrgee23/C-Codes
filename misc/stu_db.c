#include<stdio.h>
#define name 3
#define sub 3
main()
{
int stu[name][sub],b,i,j;

for(i=0;i<=2;i++)
	{	
	printf("enter num of student%d\n",i+1);
		for(j=0;j<=2;j++)
		{
		printf("enter marks in sub%d ",j+1);
		scanf("%d",&stu[i][j]);
		}
	}
	printf("subject\tenglish\tbengali\thindi\n");
	
for(i=0;i<=2;i++)
	{
		printf("STUDNT%d\t",i+1);
		
		for(j=0;j<=2;j++)
		{
		printf("%d\t",stu[i][j]);
		}
		puts("");
	}
}
