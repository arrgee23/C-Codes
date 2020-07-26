/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/


#include "dictionary.h"

unsigned int wordcount = 0;

typedef struct node
{
    char i[LENGTH+1];
    struct node* next;
}
node;

// declare the first node of our list (as a global variable)
node* first[ HASH_SIZE ] = {NULL};

node* newnode (void)
{
    node* n = malloc(sizeof(node));
    
    if(n == NULL)
    {
        printf("out of memory\n");
        exit(1);
    }
    return n;
}

void prepend(char *i, int index)
{
    // TODO
    node *nwnode = newnode();
    strcpy( nwnode->i, i );
    nwnode -> next = first[index];
    first[index] = nwnode;
}

int hash (const char* source)
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
	return 999 ;
}
 
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
	char lowword[LENGTH+1];
	strcpy(lowword,word);
	int k = strlen(lowword);
	for(int i=0; i<k;i++)
	    lowword[i] = tolower(lowword[i]);
	int index = hash (lowword);
	
	node *cursor;
		
	for(cursor = first[index]; cursor != NULL; cursor = cursor->next)
		if( strcmp(lowword,cursor->i) == 0 )
			return true;
		
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    // TODO
	
	FILE* fp = fopen( dictionary,"r" );
	if( fp != NULL )
	{
		char source[LENGTH+1];
		int index;
		while(fscanf(fp,"%s",source) != EOF)
		{
			index = hash(source);
			wordcount++;
			prepend(source,index);
		}
		fclose(fp);
		return true;
	}
	return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
	if(wordcount>0)
		return wordcount;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
	int index;
	for(index = 0; index < HASH_SIZE; index++)
	{
		while (first[index] != NULL)
		{
			node* next = first[index]->next;
			free(first[index]);
			first[index] = next;
		}
		
	}
	if(index == HASH_SIZE)
		return true;
    
	return false;
}
