#include <stdio.h>
	
	#define SIZE 8
	
	int search(int needle, int haystack[], int size)
	{
	   	int mmiddle=size/2;
        int middle=mmiddle;
        while(haystack[middle-1] != needle || middle>1 || middle<size-1)
        {
            mmiddle=mmiddle/2;
        	if(needle<haystack[middle-1])
        		middle=middle-mmiddle;
            
            else
                middle=middle+mmiddle;
        }
        
        if(haystack[middle-1] == needle)
            return 1;
        else
            return 0;
	}
	
	int main(void)
	{
	    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108};
	    printf("> ");
	    int n ;
	    scanf("%d",&n);
	    if (search(n, numbers, SIZE))
	        printf("YES\n");
	    return 0;
    }
