#include<stdio.h>
int i,j;
void add(int *p,int *q)
{
int count=0;
puts("The result of add is=");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{printf("%d\t",*(p+j+3*i)+*(q+j+3*i)); //address of numbers in an array is always consecutive.. 
	count++; //this is true for the array of any dimension thats why the variable count is used to print
	}
	puts("\n");
}

} 
void sub(int *p,int *q)
{
int count=0;
puts("The result of sub is=");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{printf("%d\t",*(p+j+3*i)-*(q+j+3*i)); //address of numbers in an array is always consecutive.. 
	count++; //this is true for the array of any dimension thats why the variable count is used to print
	}
	puts("\n");
}

} 
void scanmatrix(int *p)
{
    int i,j;
        printf("Enter the values of the 3*3 matrix row wise\n");
		printf("enter the digits separated by space. after entering a row tap enter\n");
        for(i=0;i<3;i++)
        {	printf(" row%d=",i+1);
            for(j=0;j<3;j++)
            {
                scanf("%4d",(p+3*i+j));
            }
            
        }
}
void printm(int *m)
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",*(m+3*i+j)); 
		}
	puts("\n");
	}
}

main()
{
int *p,*q;
int u[3][3]; 
int v[3][3];
scanmatrix(&v[0][0]);

scanmatrix(&u[0][0]);
printf("matrix 1=\n");
printm(v);
printf("matrix 2=\n");
printm(u);
p=&u[0][0];
q=&v[0][0];
add(p,q);
sub(p,q);
}