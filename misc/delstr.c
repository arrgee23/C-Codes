#include<stdio.h>
#include<string.h>
char c[50];
void delstr(char a[],char b[])
{
	int i,j,la,lb,flag;
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;i++)
	{	
		
		if(a[i]==b[0])//testing for the presence of substr
		{
			printf("matched %dst char entering in\n",i+1);
			flag=1; //1 FOR TRUE 0 false
			for(j=0;j<lb;j++)
			{
			
				if(a[i+j]!=b[j]) 
				{
					flag=0;	
					printf("didnt match %dst char with %dst char \n",i+1+j,j+1);
				}
			}
		}//comparson ends
			
	
	}
}
int main()
{
	char a[50],b[50];
	puts("enter string");
	scanf("%s",a);
	puts("enter the substring u want 2 remove");
	scanf("%s",b);
	delstr(a,b);
}
