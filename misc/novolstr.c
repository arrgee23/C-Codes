#include<stdio.h>

int vowel (char a) /*function to determine if a character is a vowel*/
{
	int vow=0; //this function takes a char input and returns int //
	if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
	vow=1;
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
		if( vowel(a[i])==1 )
		count++;
	}
	printf("number of vowels in string \"%s\" is %d\n",a,count);
}