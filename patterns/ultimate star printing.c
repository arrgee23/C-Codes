#include <stdio.h>
main()//Rahul Gautam; 12 aug 2012; 11.50 a.m.//
{
	int number,d=1,m,k;
	printf("print the number of lines of %c u want 2 see\n",1);

	
	scanf("%d",&number); //scanning number of $ lines//
	if (number<=40)
	for(d=1;d<=number;d++)  //looping//
	{
		
		for(k=1;k<=number-d;k++) //this is the intelligent part... figure it out urself//
		{
			printf(" "); //printing blank spaces shifts the stars rightwards//
		}
		
		for(m=1;m<=2*d-1;m++)
		{
			printf("%c",1); // nothing special.. i just love money//
		}
	
		printf("\n"); //the end//
	}
else
puts("you should input a number lower than 41");
}