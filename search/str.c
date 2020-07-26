#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "list1.h"

bool load (void);
int hash (char*);
bool check (char*,int);
int wordcount =0;
int main()
{
	
	if(load() == true)
	{
		char word[45];
		printf("Enter the word to search: ");
		scanf("%s",word);
			int i;
		int k=strlen(word);
		for(i=0;i<k; i++)
			word[i] = tolower(word[i]);
		int index = hash(word);
		if(check(word,index)==true)
			printf("found!! Correct spelling");
		else
			printf("Spelling mistake\n");
		freemem();
	}
	else
		return 1;
	return 0;
}

bool load (void)
{
	FILE *fp = fopen("large","r");
	if( fp != NULL )
	{
	
	char source[45];
	int index;
	printf("loading words...\n");
	while(fscanf(fp,"%s",source) != EOF)
	{
		index = hash(source);
		wordcount++;
		prepend(source,index);
	}
	fclose(fp);
	printf("Done loading %d words...\n",wordcount);
	return true;
	}
	else
		return false;
}
//working perfectly
int hash (char* source)
{
	switch (source[0])
	{
		case 'a' : return 0;
		case 'b' : return 1;
		case 'c' : return 2;
		case 'd' : return 3;
		case 'e' : return 4;
		case 'f' : return 5;
		case 'g' : return 6;
		case 'h' : return 7;
		case 'i' : return 8;
		case 'j' : return 9;
		case 'k' : return 10;
		case 'l' : return 11;
		case 'm' : return 12;
		case 'n' : return 13;
		case 'o' : return 14;
		case 'p' : return 15;
		case 'q' : return 16;
		case 'r' : return 17;
		case 's' : return 18;
		case 't' : return 19;
		case 'u' : return 20;
		case 'v' : return 21;
		case 'w' : return 22;
		case 'x' : return 23;
		case 'y' : return 24;
		case 'z' : return 25;
	}
}

bool check(char *word,int index)
{
	
		node *cursor;
		
		for(cursor = first[index]; cursor != NULL; cursor = cursor->next)
			if( strcmp(word,cursor->i) == 0 )
				return true;
		
		
	return false;
}