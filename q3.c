/*************************************************************************************************************************
* program that merges 2 sorted linked lists so that after the merging operation it still remains sorted
***************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>




typedef struct node{
                                int num;
                                struct node * next;
                            }node;

void insert (node* ); //inserts members in the list


int main(void)
{
    node * head;
    insert (head);
    printf("%d",head ->num);

    return 0;
}


void insert (node * ptr)
{
    ptr=malloc(sizeof(node)); //allocating space for the node
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    ptr ->num = n;
    ptr->next=NULL;

}
