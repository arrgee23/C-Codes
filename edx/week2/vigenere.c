/**************************************************************************************************
#RAHUL GAUTAM
???VIGENERE CIPHER?????
*Program to cipher a string.. if p is some plaintext and k is a keyword 
(i.e., an alphbetical string, whereby A and a represent 0, while Z and z represent 25), 
then each letter, ci, in the ciphertext, c, is computed as: ci = (pi + kj) % 26
Note this cipher's use of kj as opposed to just k. And recall that, if k is shorter than p, then the 
letters in k must be reused cyclically as many times as it takes to encrypt p.

*Takes a command line key input
*cases are presarved and non alphabetical characters are left unchanged
***************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int transformer(char *word,int count);
int main(int argc, char* argv[]) //command line arguments that the program 
{
	int length,key,i,j,count=0;
	char name[100];
	
	if(argc>2 || argv<=0)// the program should exit when a non integer or negetive argument is entered
		//return 1;    // it should also exit when more than 1 arguments are entered
		
	gets(name);
	length=strlen(name);

	
	for(i=0;i<length;i++)
	{
		if((name[i]>64 && name[i]<91) || (name[i]>96 && name[i]<123))// the program should cipher only alphabets and case should be preserved
		{
			key=transformer(argv[1],count%strlen(argv[1]));
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
			
			count++;	
		}
		else //non alphabetical characters
		printf("%c",name[i]);
	}	
	puts("\n");
}


int transformer(char *word,int count)
{
	int key;
	
	if(word[count]>64 && word[count]<91) //for capital letters
		key=word[count]-65;
	
	if(word[count]>96 && word[count]<123) //for small letters
		key=word[count]-97;
	return key;	
}