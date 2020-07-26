#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void list (void)
{
printf("1=blood test 40\n2=urine 50\n");
}

main()
{
	
	int choice,i,total=0,array[40],count=0;
	char wtf;
	
	do
	{
		list();
		puts("enter ur choice: ");
		scanf("%d",&choice);
		array[count]=choice;
		count++;
		system("cls");
		switch(choice)
		{
			case 1:
			puts("test xyz charge 40\n");
			total=total+40;
			break;
			
			case 2:
			puts("test xyz charge 50\n");
			total=total+50;
			break;
			
			default:
			printf("invalid input\n");
			break;
		}
		printf("do u wish to enter another choice? y/n");
		scanf("%s",&wtf);
	}
	while(wtf=='y');
	//printing
	system("cls");
	for(i=0;i<=count;i++)
	{
		switch(array[i])
		{
			case 1:
			puts("test 1 charge \t\t40\n");
			break;
			
			case 2:
			puts("test 2 charge \t\t50\n");
			break;
			
			default:
			break;
		}
	}
	printf("Total=%d",total);
}