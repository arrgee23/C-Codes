#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* openFileNReadLne(char* filename);
int countWordsInLine(char* Line);

int main()
{
	//printf("Enter the name of the textfile in current directory in filename.txt format\n");
	char* name="hello.txt";
	//scanf("%s",name);
	printf("The number of words in the textfile is %d\n",countWordsInLine(openFileNReadLne(name)));
	
return 0;
}

char* openFileNReadLne(char* filename)
{
	FILE* fp = fopen(filename,"r");
	
	if(fp == NULL)
		exit(0);
	char buffer[1024];
	
	int count =0;
	char ch;
	while((ch = fgetc(fp)) != EOF)
	{
		buffer[count] = ch;
		count++;
	}
	// last character made null character
	buffer[count] = '\0';
	fclose(fp);
	
	return buffer;
}

int countWordsInLine(char* Line)
{
	int wordcount = 0;
	
	int i=0;
	while(Line[i])
	{
		i++;
		if(Line[i] == ' ')
			wordcount++;
	}
	
	return wordcount+1;
}