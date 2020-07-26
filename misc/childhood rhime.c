#include<stdio.h>
int main(void)
{
    int i;
	char *number[]={"one","two","three","four","five","six","seven","eight","nine","ten"};
	char *item[]={"thumb","shoe","knee","door","hive","sticks","heaven","gate","spine","again"};

	for( i=1;i<11;i++)
	{
		printf("This old man, he played %s\n",number[i-1]);
		printf("He played knick-knack %s %s\n","on my",item[i-1]);
		printf("Knick-knack paddywhack, give your dog a bone\n");
		printf("This old man came rolling home\n\n\n");
		if(i==7)
			{
			printf("This old man, he played %s\n",number[i-1]);
		printf("He played knick-knack %s %s\n","up in",item[i-1]);
		printf("Knick-knack paddywhack, give your dog a bone\n");
		printf("This old man came rolling home\n\n\n");
			}
		if(i==10)
			{
			printf("This old man, he played %s\n",number[i-1]);
		printf("He played knick-knack %s %s\n","once",item[i-1]);
		printf("Knick-knack paddywhack, give your dog a bone\n");
		printf("This old man came rolling home\n\n\n");
			}
	}
	return 0;
}
