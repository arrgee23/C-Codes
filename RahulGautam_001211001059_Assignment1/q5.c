/***********************************************************************
	*Performs the following using arrays:
	*Addition of two polynomials.
	*Multiplication of two polynomials.
	# RAHUL GAUTAM
***********************************************************************/
#include<stdio.h>

//declaring a global  variable that will be used in every function to calculate complexity
int complexity = 0;

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
	
	puts("\n###Polynomials are displayed in {coefficient,exponent} format###");
	printf("\nPolynomial a is: ");
	print(a,na);
	printf("\nPolynomial b is: ");
	print(b,nb);
	
	puts("\nADDED POLYNOMIAL: ");
	int nc = poly_add(a,b,na,nb,c);
	print(c,nc);
	
	puts("\nMULTIPLIED POLYNOMIAL: ");
	int nd = poly_mul(a,b,na,nb,d);
	print(d,nd);
	printf("\n\n\nNo of Steps = %d",complexity);
return 0;
}

int input(term a[])
{
	
	int count = 0;
	int n;
	printf("How many terms do u wish to enter: ");
	do
	{
		scanf("%d",&n);
	}
	while(n <= 0 || n > 100);
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

//sorts a polinomial ascending exponent order
void sort(term a[],int *num)
{
	int i;
	for(i=0;i<*num - 1;i++)
	{
		complexity++;complexity++;
		if( a[i].expo > a[i+1].expo)
		{
			complexity++;complexity++;
			int tempexpo = a[i].expo;
			float tempcoeff = a[i].coeff;
			a[i].expo = a[i+1].expo;
			a[i].coeff = a[i+1].coeff;
			a[i+1].expo = tempexpo;
			a[i+1].coeff = tempcoeff;
		}
	}
}
//adds polimomials
int poly_add (term a[], term b[],int na,int nb,term added[])
{
	int count, i=0, j=0;
 
	int sum = na + nb;
	for (count = 0; count < sum;) 
	{
		complexity++;complexity++;
		//inputs elements till every element of any subarry is added
		if (i < na && j < nb) 
		{
			complexity++;complexity++;
			if (a[i].expo < b[j].expo) 
			{
				complexity++;complexity++;
				added[count].coeff = a[i].coeff;
				added[count].expo = a[i].expo;
				i++;
			}
			else if(a[i].expo == b[j].expo)
			{
				complexity++;complexity++;
				added[count].expo = b[j].expo;
				added[count].coeff = b[j].coeff + a[i].coeff;
				j++;
				i++;
				sum--;
			}
			else
			{
				complexity++;complexity++;
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
			complexity++;complexity++;
			while(count < sum)
			{
				complexity++;complexity++;
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
				complexity++;complexity++;
				added[count].coeff = a[i].coeff;
				added[count].expo = a[i].expo;
				i++;
				count++;
			}
		}
	}
	return count;
}
//multiplies two polynomials
int poly_mul (term a[], term b[],int na,int nb,term multiplied[])
{
	int count=0, i=0, j=0;
	for(i=0; i<na; i++)
		for(j=0; j<nb; j++)
		{
			complexity++;complexity++;
			multiplied[count].expo = b[j].expo + a[i].expo;
			multiplied[count].coeff = b[j].coeff * a[i].coeff;
			count++;
		}
	
	return count;
}
