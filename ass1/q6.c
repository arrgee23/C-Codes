#include<stdio.h>
#include<string.h>

int complexity = 0;

int main()
{
    int a[500],b[500],sum[500];
    int ac=0,bc=0,sc=0;
    char num1[500],num2[500];
    
	printf("Enter first number : ");
    scanf("%s",&num1); //taking first number from user in string format
    printf("\nEnter second number : ");
    scanf("%s",&num2); //taking second number from user in string format

    char *pa = num1; //pointer to first number
    char *pb = num2; //pointer to second number

    //storing  first string number in the integer array
    while(*pa)//loop while runs untill it gets a null character
	{  
        a[ac++] = *pa++ - 48;  //48 is ASCII value of character zero so any (Number - 48) yields its integer value
    }

    while(*pb)
	{
        b[bc++] = *pb++ - 48;
    }
	
	int i;
    int reminder = 0;
    //addition of two numbers
    if(ac<bc)
	{
        for(i = ac;i > 0;i--)
		{
            sum[sc++]= ((a[i-1] + b[--bc]) + reminder)%10;
            reminder = ((a[i-1] + b[bc]) + reminder)/10;
        }
        while(bc>0)
		{
            sum[sc++] = b[--bc] + reminder;
            reminder = 0;
        }
    }
    else
	{
        for(i = bc;i > 0;i--)
		{
            sum[sc++]= ((b[i-1] + a[--ac]) + reminder)%10;
            reminder = ((b[i-1] + a[ac]) + reminder)/10;
        }
      
		if(ac==0 && reminder==1)
            sum[sc++] = reminder;
        
		while(ac>0)
		{
            sum[sc++] = a[--ac] + reminder;
            reminder = 0;
        }
    }
    //printing in reverse order
	printf("Sum of both number is : ");
    for(i=sc-1;i>=0;i--)
	{
         printf("%d",sum[i]);
    }
    return 0;
}
