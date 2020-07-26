/******************************************************************************************
	* C program that concatenets two 1-d arrays
	# RAHUL GAUTAM	
******************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

//displays 1d array
void display(int *p, int n)
{
	int i=0;
    printf("\n\n\n ");
    
    for(i=0;i<n;i++)
       { 
			printf("%d\t",p[i]);
       }
    printf("\n");
}

//function that reads an 1d array and returns total number of elements
int* read(int n)
{
	int i,*a;
	printf("\nEnter elements :\n");
    a=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    return a;
}
//concatenates horizontally
int* cat(int *a,int *b,int n1,int n2)
{
	int i=0,j=0,*c;
	c=(int*)calloc((n1+n2),sizeof(int));
  
	for(i=0;i<n1;i++)
		{c[j++]=a[i];complexity++;}
	for(i=0;i<n2;i++)
		{c[j++]=b[i]; complexity++;}
    
	return c;
}
//concatenates vertically int ** is used for allocating a 2d array
int** cat_ver(int *a,int *b,int n)
{ 
	int i=0,j=0,**c;

	c=(int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
		{c[i]=(int*)calloc(2,sizeof(int));complexity++;}


	for(i=0;i<n;i++)
		{c[0][j++]=a[i];complexity++;}
   
	j=0;

	for(i=0;i<n;i++)
		{c[1][j++]=b[i];complexity++;}
	
	return c;
}


int main()
{ 
	int *c,**d,n3=0,i=0,j=0;
   
	printf("\nEnter no. of elements for array1: ");
	int n1;
    scanf("%d",&n1);
	int *a=read(n1);
	
	printf("\nEnter no. of elements for array2: ");
	int n2;
    scanf("%d",&n2);
	int *b=read(n2);
	
	printf("\n\nWhat do u wish to do: \n1.cat horizontally in order\n2.Concatenate horizontally in reverse order\n3.Concatenate vertically\n\nEnter your choice: \n");
	int choice;
	scanf("%d",&choice);
	complexity++;
	switch(choice)
	{ 
	case 1: 
		complexity++;
		c=(int*)cat(a,b,n1,n2);
		display(c,n1+n2);
		break;


	case 2:  
		c=(int*)cat(b,a,n2,n1);
        display(c,n1+n2);
		complexity++;
        break;
   
	case 3: 
		complexity++;
		if(n1!=n2)
        {
			printf("\nNot possible choice");
            return 1;
		}
        d=(int**)cat_ver(a,b,n1);
		
        printf("\n\nResultant Matrix\n\n ");
		for(i=0;i<2;i++)
        { 
			for(j=0;j<n1;j++)
                printf("%d\t",d[i][j]);
            printf("\n ");
        }
		break;

    default: 
		printf("invalid choice TRY AGAIN!!!");
		return 2;
  }


printf("\n\n\nNo of Steps = %d",complexity);


 return 0;
}

