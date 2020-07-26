/***********************************************************************
 * RAHUL GAUTAM
 * Singly linked lists
 * Demonstrates some useful function on list for a list of numbers.
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node* next;
}
node;

// linked list
node* first = NULL;

// prototypes
void delete(void);
void find(void);
void insert_sorted(void);
void print(void);
void append(void);
void prepend(void);
void new(void);
int counter(void);
void sort(void);
void reverse(void);

int main(void)
{
    int c;
    do
    {
        // print instructions
        printf("\nMENU\n\n"
               "1 - delete\n"
               "2 - find\n"
               "3 - insert_sorted\n"
               "4 - prepend\n"
			   "5 - append\n"
			   "6 - sort\n"
			   "7 - print\n"
			   "8 - reverse\n"
               "0 - quit\n\n");

        // get command
        printf("Command: ");
       scanf("%d",&c);

        // try to execute command
        switch (c)
        {
            case 1: delete(); break;
            case 2: find(); break;
            case 3: insert_sorted(); break;
            case 4: prepend(); break;
			case 5: append(); break;
			case 6: sort(); break;
			case 7: print(); break;
			case 8: reverse(); break;
        }
    }
    while (c != 0);

    // free list before quitting
    node* ptr = first;
    while (ptr != NULL)
    {
        node *predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }

    return 0;
}

/**
 * Tries to delete a number.
 */
void delete(void)
{
    // prompt user for number
    printf("Number to delete: ");
    int n ;
	scanf("%d",&n);

    // get list's first node
    node* ptr = first;

    // try to delete number from list
    node* predptr = NULL;
    while (ptr != NULL)
    {
        // check for number
        if (ptr->n == n)
        {
            // delete from head
            if (ptr == first)
            {
                first = ptr->next;
                free(ptr);
            }

            // delete from middle or tail
            else
            {
                predptr->next = ptr->next;
                free(ptr);
            }

            // all done
            break;
        }
        else
        {
            predptr = ptr;
            ptr = ptr->next;
        }
    }

    // print list
    print();
}

/**
 * Tries to insert_sorted a number into list.
 */
void insert_sorted(void)
{
    // try to instantiate node for number
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
        return;

    // initialize node
    printf("Number to insert_sorted: ");
	int l;
	scanf("%d",&l);
    newptr->n = l;
    newptr->next = NULL;

    // check for empty list
    if (first == NULL)
        first = newptr;

    // else check if number belongs at list's head
    else if (newptr->n < first->n)
    {
        newptr->next = first;
        first = newptr;
    }

    // else try to insert_sorted number in middle or tail
    else
    {
        node* predptr = first;
        while (1)
        {
            // avoid duplicates
            if (predptr->n == newptr->n)
            {
                free(newptr);
                break;
            }

            // check for insert_sortedion at tail
            else if (predptr->next == NULL)
            {
                predptr->next = newptr;
                break;
            }

            // check for insert_sortedion in middle
            else if (predptr->next->n > newptr->n)
            {
                newptr->next = predptr->next;
                predptr->next = newptr;
                break;
            }

            // update pointer
            predptr = predptr->next;
        }
    }

    // print list
    print();
}

/**
 * Tries to find a number in list.
 */
void find(void)
{
    // prompt user for number
    printf("Number to find: ");
	int l;
	scanf("%d",&l);
    int n = l;

    // get list's first node
    node* ptr = first;

    // try to find number
    while (ptr != NULL)
    {
        if (ptr->n == n)
        {
            printf("\nFound %d!\n", n);
            break;
        }
        ptr = ptr->next;
    }
}

/**
 * Traverses list, printing its numbers.
 */
void print(void)
{
    // traverse list
    printf("\nLIST IS NOW: ");
    node* ptr = first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->n);
        ptr = ptr->next;
    }

    // flush standard output since we haven't outputted any newlines yet
    fflush(stdout);
	
    printf("\n\n");
	printf("Elements in list = %d \n",counter());
}
/**
 * prepends a number in the list
 */
void prepend(void)
{
	// try to instantiate node for number
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
        return;

    // initialize node
    printf("Number to prepend: ");
	int l;
	scanf("%d",&l);
    newptr->n = l;
    newptr->next = first;
	
	first = newptr;
	print();
}
/**
 * appends a number in the list
 */
void append(void)
{
	// try to instantiate node for number
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
        return;

    // initialize node
    printf("Number to append: ");
	int l;
	scanf("%d",&l);
    newptr->n = l;
	newptr -> next = NULL;
	
	// insert at the beginning if list is empty
	if(first == NULL)
	{
		first = newptr;
	}
	
	else
	{
		// insetring it at the correct place
		node* cursor = first;
	
		// finding the last elemnt
		while(cursor -> next != NULL)
			cursor = cursor -> next;
		
		// making the last element to point to the newly created node
			cursor -> next = newptr;
	}
	print();
}
/**
 * returns the number of elements in the list
 */
int counter(void)
{
	node* ptr = first;
	int count = 0;
	while(ptr != NULL)
	{
		ptr = ptr -> next;
		count++;
	}
	return count;
}
/**
 * sorts the list in ascending order
 */
void sort(void)
{
	node *ptr;
	int count = counter();
	int i;
	// iterate (number of elements - 1) time
	for(i=0; i<count - 1; i++)
	{
		// uses the logic of bubbble sort
		for(ptr = first; ptr -> next != NULL ; ptr = ptr -> next)
		{
			node* nextptr = ptr -> next;
			
			if(ptr -> n > nextptr -> n)
			{
				int temp = nextptr -> n;
				nextptr -> n = ptr -> n;
				ptr -> n = temp;
			}
		}
	}

	print();
}
/**
 * reverses the list from a specified point
 */
void reverse(void)
{
	printf("From which element do you want to reverse: ");
	int n;
	scanf("%d",&n);
	
    node* ptr = first;

    // try to find number 
    while (ptr != NULL)
    {
        if (ptr->n == n)
        {
            break;
        }
        ptr = ptr->next;
    }// now ptr has the address of the node or NULL
    
	// declares new list
	node *revfirst = NULL;
		
    if(ptr == NULL)
	{
		printf("Number not present!!\n");
		exit(1);
	}
	else
	{	
		while (ptr != NULL)
		{
			// makes a new list to save the number in reversed order
			node* newptr = malloc(sizeof(node));
			if (newptr == NULL)
				return;

			// initialize node
			newptr->n = ptr -> n;
			newptr->next = revfirst;
	
			revfirst = newptr;
			
			ptr = ptr->next;
		}
	}
	// prints the list
	printf("\nREVERSED LIST IS: ");
    node* crsr = revfirst;
    while (crsr != NULL)
    {
        printf("%d ", crsr->n);
        crsr = crsr->next;
    }

    // flush standard output since we haven't outputted any newlines yet
    fflush(stdout);
}
