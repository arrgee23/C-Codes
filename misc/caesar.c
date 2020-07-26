/**************************************************************************************************
#RAHUL GAUTAM
*Program to cipher a string desired number of places.
*Takes a command line key input
*cases are presarved and non alphabetical characters are left unchanged
***************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) //command line arguments that the program 
{
	int length,key,i,j;
	char name[100];
	j=atoi(argv[1]);//since argv[0] is the name of the file
	key=j%26; //to accept a value greater than 26 and cipher
	
	if(argc>2 || j<=0)// the program should exit when a non integer or negetive argument is entered
		return 1;    // it should also exit when more than 1 arguments are entered
		
	printf("enter something to cipher= ");
	gets(name);
	length=strlen(name);
	printf("Your ciphered word is:");
	
	for(i=0;i<length;i++)
	{
		if((name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123))// the program should cipher only alphabets and case should be preserved
		{
			if(name[i]>96 && name[i]<123) //for small letters
				if (name[i]+key<=122) 
					printf("%c",name[i]+key);
				else //wrapping around
					printf("%c",name[i]-26+key);
			if(name[i]>64 && name[i]<91) //for capital letters
				if (name[i]+key<=90)
					printf("%c",name[i]+key);
				else
					printf("%c",name[i]-26+key);		
		}
		else //non alphabetical characters
		printf("%c",name[i]);
	}	
	puts("\n");
}