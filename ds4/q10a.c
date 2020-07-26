#include<stdio.h>
#include<stdlib.h>

int collision = 0;

int hash(int value);
void probe(int* cache, int value);

int count = 0;

int main()
{
	FILE* fp = fopen("NumberGen_4_digit.txt" , "r");
	int cache[100];
	int i;
	for(i=0;i<100;i++)
		cache[i] = -1;
		
	//int chain_length[100] = {0};
	int temp;
	while(fscanf(fp,"%d",&temp) == 1)
	{
		probe(cache,temp);
	}
	fclose(fp);
	
	
	for(i=0;i<100;i++)
	{	
		printf("cache[%d] = %d",i,cache[i]); puts("");
	}
	
	//printf("\n\n Avg chain length = %f",sum/100.0);
	
	return 0;
}

int hash(int value)
{
	return value % 100;
}

void probe(int* cache, int value)
{
	while(count < 100)
	{
		// insert if empty space
		if(cache[hash(value)] == -1)
			cache[hash(value)] = value;
		// seach for the next empty space
		else
		{
			int i = hash(value);
			int j = 0;
			while(cache[i%100] != -1 || j < 100)
			{	i++;j++;}
				
			cache[i%100] = value;
		}
		count++;
	}
}