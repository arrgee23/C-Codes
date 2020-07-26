#include<stdio.h>
int main (void)
{
	int matrix[][4]={
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9,10,11,12}
					};
	int R=0,C=0,row=0,col=0;
	while(R<3)
	{
		C=0;
		while(C<4)
		{
			row=R;col=C;
			
			while(row<3 && col<4)
			{
				printf("%d ",matrix[row][col]);
				row++;col++;
			}
			C++;
			puts("");
		}
		
		R++;
	}
	return 0;
}
