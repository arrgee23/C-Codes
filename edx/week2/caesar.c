#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int length,key,i,j,k;
	j=atoi(argv[1]);
	key=j%26;
	puts("Your ciphered word is:");
	for(k=2;k<argc;k++)
	{
		length=strlen(argv[k]);
		for(i=0;i<length;i++)
		{
			if((argv[k][i]>64 && argv[k][i]<91) || (argv[k][i]>96 && argv[k][i]<123))
			{
				if(argv[k][i]>96 && argv[k][i]<123)
					
					if (argv[k][i]+key<=122)
						printf("%c",argv[k][i]+key);
					else
						printf("%c",argv[k][i]-26+key);
				
				if(argv[k][i]>64 && argv[k][i]<91)
				
					if (argv[k][i]+key<=90)
						printf("%c",argv[k][i]+key);
					else
						printf("%c",argv[k][i]-26+key);		
			}
			else
			printf("%c",argv[k][i]);
		}
		printf(" ");
	}
	puts("\n");
}