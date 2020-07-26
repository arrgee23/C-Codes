/*File handling
*writing operation
*fprintf			*/
#include<stdio.h>

int main()
{
	FILE *fp;char *kl="sonkolpo";
	int i;
	char a[50];
	puts("Enter a text to write in a text file:");
	gets(a);
	fp=fopen("myfile.txt","w");//opens in writing mode fp returns null if nothing is opened
	if(fp==NULL)
		puts("cant open file");
	fprintf(fp,"%s",a);//prints formatted string in the file same as printf
							//fprintf(<file pointer>,<format string>,<parameters>);
							//this is the general structure of fprintf
		
	printf("char printed after string input= %d\n",ftell(fp));//ftell tells the current position of file pointer
	
	/*Fputc enters single character this is the demo*/
	
	
	for(i=0;i<strlen(kl);i++)
	{
		printf("char printed after each and every char input=%d\n",ftell(fp));	
		fputc(kl[i],fp);//puts a single character during each iteration
	}
	
	fclose(fp);//closes the file
return 0;
}
