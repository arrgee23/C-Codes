/****************************************************************************
 * pointers.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Prints a given string one character per line.
 *
 * Demonstrates pointer arithmetic.
 ***************************************************************************/
       

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // get line of text
   char* s = "HOLSH hjgh ds";
    if (s == NULL)
        return 1;
 
    // print string, one character per line
    for (int i = 0, n = strlen(s); i < n; i++)
        printf("%u\n", *(s+i));
    
    // free string
    free(s);

    return 0;
}
