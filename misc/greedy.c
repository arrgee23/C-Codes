#include<stdio.h>
int main(void)
{
	float changef;
	int changei,num=0;
	printf("how much change is owed?\n");
	scanf("%f",&changef);
	while(changef<0)
	{
		printf("how much change is owed?\n");
		scanf("%f",&changef);
	}
	changef=(changef*100);
	changei=(int)changef;
	while(changei>0)
	{
		while(changei>=100)
		{
			changei=changei-100;
			num++;
		}
		while(changei>=25)
		{
			changei=changei-25;
			num++;
		}
		while(changei>=10)
		{
			changei=changei-10;
			num++;
		}
		while(changei>=50)
		{
			changei=changei-50;
			num++;
		}
		while(changei>=5)
		{
			changei=changei-5;
			num++;
		}
		while(changei>=1)
		{
			changei=changei-1;
			num++;
		}
		break;
	}
	printf("%d\n",num);
}