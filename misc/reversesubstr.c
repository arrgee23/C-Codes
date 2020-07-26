#include<stdio.h>
void compare(char a[], char b[]);
int strlngth(char x[]);
void strrev(char *m);
char *adr;
int la,lb,match;
char b[50],a[50];
int main()
{
    printf("Enter 1st string: ");
    gets (a);
    printf("Enter substring: ");
    gets (b);
    compare(a,b);
    printf("%s",a);
    return 0;
}

int strlngth(char x[])
{
	int i,count=0;
	for(i=0;i<100;i++)
	{
		if(x[i]==0)
		{break;}
		count++;
	}	
	return count;
}

void compare(char a[], char b[])//compares two strings
{
	int i,j,count=0;
    la=strlngth(a);
    lb=strlngth(b);
	
    //comparison starts
    for(i=0;i<la;i++)
    {	
        if(a[i]==b[0])//if the first letter of the string matches then it enters the inner loop

        {   
            for(j=0;j<lb;j++)
            {
                if(a[i+j]==b[j])
                    {count++;}
            }//ends
            if(count==lb)//if they match
            {   
                match=i;
                adr=&a[match];
                strrev(adr);
            }
        }
        count=0;
    }
    	
}

void strrev(char *m) //reverse a given string
{
	int i;
	
	for(i=lb-1;i>=0;i--) //the computer starts counting form 0
	{						//so the serial number of final term = (total terms-1)
		*m=b[i];
		m++;
	}
}

