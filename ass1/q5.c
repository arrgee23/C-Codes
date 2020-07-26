#include "mat.h"
#include <math.h>


typedef struct term
{
	float coeff;
	int expo;
}term;

void print (term a[], int num);
int input(term a[]);
void sort(term a[],int *num);
int poly_add (term a[], term b[],int na,int nb,term added[]);
int poly_mul (term a[], term b[],int na,int nb,term multiplied[]);

int main()
{
	int i;
	term  a[100],b[100],c[100],d[100];
	printf("For polynomial 1 ");
	int na = input(a);
	printf("For polynomial 2 ");
	int nb = input(b);
	
	sort(a,&na);
	sort(b,&nb);
	
	printf("Polynomial a is: ");
	print(a,na);
	printf("Polynomial b is: ");
	print(b,nb);
	
	puts("ADDED POLYNOMIAL: ");
	int nc = poly_add(a,b,na,nb,c);
	print(c,nc);
	
	puts("MULTIPLIED POLYNOMIAL: ");
	int nd = poly_mul(a,b,na,nb,d);
	print(d,nd);
	printf("\n\nNo of steps taken = %d\n",complexity);

return 0;
}

int input(term a[])
{
	
	int count = 0;
	int n;
	printf("How many terms do u wish to enter: ");
	scanf("%d",&n);
	while(1)
	{
		printf("enter coefficient and exponents separated by a space: ");
		scanf("%f", & a[count].coeff);
		scanf("%d", & a[count].expo );
		
		count++;
		
		if( count == n)
			break;
	} 
	
	return count;
}

void print (term a[], int num)
{
	int i;
	for(i=0; i<num;i++)
	{
		printf("{%.2f,%d} ",a[i].coeff,a[i].expo);
	}
	puts("");
}

void sort(term a[],int *num)
{
	int i;
	for(i=0;i<*num - 1;i++)
	{
		if( a[i].expo > a[i+1].expo)
		{
			int tempexpo = a[i].expo;
			float tempcoeff = a[i].coeff;
			a[i].expo = a[i+1].expo;
			a[i].coeff = a[i+1].coeff;
			a[i+1].expo = tempexpo;
			a[i+1].coeff = tempcoeff;
		}
	}
	for(i=0;i<*num - 1;i++)
	{
		if(a[i].expo == a[i+1].expo)
		{
			
		}
	}
}

int poly_add (term a[], term b[],int na,int nb,term added[])
{
	int count, i=0, j=0;
 
	int sum = na + nb;
	for (count = 0; count < sum;) 
	{
		//inputs elements till every element of any subarry is added
		if (i < na && j < nb) 
		{
			if (a[i].expo < b[j].expo) 
			{
				added[count].coeff = a[i].coeff;
				added[count].expo = a[i].expo;
				i++;
			}
			else if(a[i].expo == b[j].expo)
			{
				added[count].expo = b[j].expo;
				added[count].coeff = b[j].coeff + a[i].coeff;
				j++;
				i++;
				sum--;
			}
			else
			{
				added[count].coeff = b[j].coeff;
				added[count].expo = b[j].expo;
				j++;
			}
			count++;
		}
	
		//when every element of arrat 'a' is added it populets the
		//merged array with elements from 'b' array
		else if (i == na) 
		{
			while(count < sum)
			{
				added[count].coeff = b[j].coeff;
				added[count].expo = b[j].expo;
				j++;
				count++;
			}
		}
	
		else 
		{
			while ( count < sum) 
			{
				added[count].coeff = a[i].coeff;
				added[count].expo = a[i].expo;
				i++;
				count++;
			}
		}
	}
	return count;
}

int poly_mul (term a[], term b[],int na,int nb,term multiplied[])
{
	int count=0, i=0, j=0;
 
	for(i=0;i<na;i++)
	{
		for(j=0;j<nb;j++)
		{
			multiplied[count].coeff = a[i].coeff * b[j].coeff;
			multiplied[count].expo = a[i].expo + b[j].expo;
			count++;
		}
	}
	return count;
}
