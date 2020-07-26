#include<stdio.h>
#include<windows.h>
int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int i;
	for(i=1;i<=100;i++)
	{
		SetConsoleTextAttribute(consoleHandle,i);
		printf("this is color [%d]\n",i);
	}
	return 0;
}