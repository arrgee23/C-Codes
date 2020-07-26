#include <stdio.h>
int la,lb;
int match;
char a[50],b[50];
void compare(char a[], char b[]);
void strdel(void);
int strlngth(char x[]);

int main()
{
    printf("Enter 1st string: ");
    gets (a);
    printf("Enter substring: ");
    gets (b);
    compare(a,b);
    printf("the final string is=%s\n",a);
    return 0;
}

int strlngth(char x[]) //calculates length of the string
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
	int true=0,count=0,i,j;
    la=strlngth(a);
    lb=strlngth(b);
	
    
    //comparison starts
    for(i=0;i<la;i++)
    {	
        if(a[i]==b[0])//if the first letter of the string matches then it enters the inner loop

        {    printf("enters for i=%d",i);
            for(j=0;j<lb;j++)
            {
                if(a[i+j]==b[j])
                    {count++;}
            }//ends
            if(count==lb)//if they match
            {   
                match=i;printf("match found");
                strdel();
            }
        }
        count=0;
    }
    	
}

void strdel(void)

{
	int i=0,j=0,lx,ly;
	char x[50],y[50],c[500];
	for(i=match+lb,j=0;i<=la;i++,j++)//initalises 2nd part of unmatched string to char array x
	{
		x[j]=a[i];
	}x[j]=0;
	for(j=0;j<match;j++) 
	{
		y[j]=a[j];
	}
	y[j]=0;
	ly=strlngth(y);
	lx=strlngth(x);
	
	for(i=0;i<50;i++)//setting every character to null
	a[i]=0;
	
	for(i=0;i<ly;i++) //the length of the joined string will be the total length of bot the strings
	{
		if(i<ly)
		a[i]=y[i];
	}
	for(i=0;i<lx;i++)
	{
		a[i+ly]=x[i]; //this is to initialise terms in c[] after first few terms has been initialised
	}

	
compare(a,b);
}




