#include<stdio.h>
main()
{
	int a,b,r,i=0,c[20],k;
	puts("enter a number 2 get its binary equivalent;\n");
	printf("The number = ");
	scanf("%d",&a);
	while(a!=0)
	{
		b=a/2;
		r=a%2;
		c[i]=r;
		a=b;
		i++;
	}          //i is incremented once again after the execution of the loop without having any corresponding array value
	printf("Tbinary equivalent is = ");
	for(k=i-1;k>=0;k--) //for the aforesaid reason c[i] has garbage value
   { printf("%d",c[k]); } //so we start printing frm c[i-1]
    puts("\n\n");
}
