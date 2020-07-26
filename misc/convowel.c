#include<stdio.h>
/*function to determine if a character is a vowel*/
int vowel (char a) //this function takes a char input and returns int//
{
	int vow=0; //0 for false 
	if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
	vow=1; //1 for true
	return(vow);
}
int main()
{
	char a[100];
	int count=0,i;
	puts("enter the word");
	scanf("%s",&a);
	for(i=0;i<100;i++)
	{
		if( vowel(a[i])==1 && vowel(a[i+1])==1 )
		count++;
		else if( vowel(a[i])==1 && vowel(a[i-1])==1 )
		count++;
		printf("execution%d || char %c || count=%d\n",i,a[i],count);
		if(a[i]==0)
		break;
	}
	printf("number of consecutive vowels in string \"%s\" is %d\n",a,count);
}