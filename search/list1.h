/****************************************************************************
 * list1.h
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Defines a node for a linked list of integers.
 ***************************************************************************/
       
typedef struct node
{
    char i[45];
    struct node* next;
}
node;
// declare the first node of our list (as a global variable)
node* first[26] = {NULL};

node* newnode (void)
{
    node* n = malloc(sizeof(node));
    
    if(n == NULL)
    {
        fprintf(stderr,"out of memory\n");
        exit(1);
    }
    return n;
}

void print (int index)
{
	node *cursor;
	printf("index %d :",index);
	for(cursor = first[index]; cursor != NULL; cursor = cursor->next)
		printf("%s ",cursor->i);
	puts("");
}

void prepend(char *i, int index)
{
    // TODO
    node *nwnode = newnode();
    strcpy( nwnode->i, i );
    nwnode -> next = first[index];
    first[index] = nwnode;
}

/*void append(int i)
{
    // TODO
    
    //creates a new node
    node *new_node = newnode();
    
    //initializes values
    new_node->i = i;
    new_node->next =NULL;
	
    //inserts if list is empty
    if (first == NULL ) 
    {
        first = new_node;
    }
    
    //searches for the last node
    else
    {
        node *cursor = first;
        
        while(cursor->next != NULL)
        {
          cursor = cursor->next;
        }
        //now cursor contains the address of last node

        //initializing the values
        cursor->next = new_node;
    }
	
}*/

void freemem(void)
{
	int index;
	for(index = 0; index<26; index++)
	{
		while (first[index] != NULL)
		{
			node* next = first[index]->next;
			free(first[index]);
			first[index] = next;
		}
		
	}
}

/*
void insert_sorted(int i)
{
    // TODO
    node *new_node = newnode();
	new_node->i = i;
	new_node->next = NULL;
	
	//appends if list is empty
	if (first == NULL)
	{
		new_node -> next = first;
		first = new_node;
	}
	
	else
	{
		node *cursor = first;
		node *nxtcursor;
		//traverses thru the list 
		while(cursor->next != NULL)
		{	
			nxtcursor = cursor->next;
			
			//for entry in the middle
			if( (cursor->i) < i && (nxtcursor->i) >= i && nxtcursor != NULL )
			{
				cursor->next = new_node;
				new_node->next = nxtcursor;
			}
			cursor = cursor->next;
		}
		
		if(new_node->next == NULL)
		{
			nxtcursor = new_node;
		}
	}
    
}*/