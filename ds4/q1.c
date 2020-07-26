#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

#define SPACE 15

void treeprinter (int* root);
void print(tree* root);
int search( int* root, int num,int index);
void insert( int* root, int num,int index);
void postorder(int* root,int index);
void preorder(int* root,int index);
void inorder(int* root,int index);
void delete(int* root,int index);
int successor(int *root,int index);
int height(int* root,int index);

int main()
{
	int gaach[SPACE] = {-1};
	
	int i;
	for(i=0;i<SPACE; i++)
		gaach[i] = -1;
	
	tree* root;
		
	while(1)
	{
		int n;
		printf("1. insert\n2. search\n3. print Pre-order\n4. print post-order\n5. print In-order\n6. height\n7. delete\n8. exit\n\tCOMMAND: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: 
						printf("\nEnter number to insert: ");
						int k;
						scanf("%d",&k);
						insert(gaach,k,0);
						treeprinter(gaach);
						break;
					
					
			case 2: 
						printf("\nEnter number to search: ");
						int m;
						scanf("%d",&m);
						if(search(gaach,m,0) != -1)
							printf("\nFOUND\n");
						else
							printf("\nDOES NOT  EXIST\n");
						break;
					
					
			case 3: preorder(gaach,0);puts("");break;
			
			case 4: postorder(gaach,0);puts("");break;
			
			case 5: inorder(gaach,0);puts("");break;
			
			case 6: printf("\nThe height of the tree is = %d\n",height(gaach,0));break;
			
			case 7: 	printf("\nEnter number to delete: ");
				
						scanf("%d",&m);
						int todelete = search(gaach,m,0);
						if(todelete != -1)
						{
							delete(gaach,todelete);
						}
						else
							printf("\nDOES NOT  EXIST\n");
						treeprinter(gaach);
						break;
			
			case 8: return 0;
			
			default: printf("\nInvalid input");
			
		}					
	}
}
// returns the address of the searched number on success NULL in failure
int search( int* root, int num,int index)
{	
	if(index > SPACE)
		return -1;
	else if ( *(root + index) == -1 )
	{
		return -1;
	}
	else 
	{
		if(*(root + index) < num)
			search(root,num,2*(index + 1));//rightchild index
		else if(*(root + index) == num)
			return index;
		else
			search(root,num,2 * (index + 1) - 1);//leftchild index
	}
}


/* inserts a new node in a binary tree */
void insert ( int* root, int num,int index )
{
	if(index > SPACE)
		return;
	else if ( *(root + index) == -1 )
	{
		*(root + index) = num;
		return;
	}
	else 
	{
		if(*(root + index) < num)
			insert(root,num,2*(index + 1));//rightchild index
		else
			insert(root,num,2 * (index + 1) - 1);//leftchild index
	}
}


/**
	postorder traversal
	1. traverse left subtree
	2. traverse right subtree
	3. visit root
*/
void postorder(int* root,int index)
{
	if(*(root + index) != -1)
	{
		if(2*(index + 1)-1 != -1)
			postorder(root,2*(index + 1)-1);
		
		if(2*(index + 1) != -1)
			postorder(root,2*(index + 1));
			
		printf("%d ",root[index]);
	}
}

/**
	preorder traversal
	1. visit root
	2. traverse left subtree
	3. traverse right subtree
*/
void preorder(int* root,int index)
{
	if(*(root + index) != -1)
	{
		printf("%d ",root[index]);
		
		if(2*(index + 1)-1 != -1)
			preorder(root,2*(index + 1)-1);
		
		if(2*(index + 1) != -1)
			preorder(root,2*(index + 1));
			
		
	}
}
/**
	1. Traverse left subtree
	2. Visit the root
	3. Traverse right subtree
*/

void inorder(int* root,int index)
{
	if(*(root + index) != -1)
	{
		if(2*(index + 1)-1 != -1)
			inorder(root,2*(index + 1)-1);
			
		printf("%d ",root[index]);
		
		if(2*(index + 1) != -1)
			inorder(root,2*(index + 1));
	}
}

int height(int* root,int index)
{
	int i = index;
	
	if(root[index] == -1)
		return 0;
		
	else
	{
		int h,lh,rh;
		h=lh=rh=0;
		
		// calculates height of the left subtree
		if(root[2*(i+1)-1]!= -1)
			lh = (1+height(root,2*(i+1)-1));
			
		// calculates height of the right subtree
		else if(2*(i+1)!= -1)
			rh = (1+height(root,2*(i+1)));
		
		//returns the bigger number	
		h = lh>rh ? lh:rh;
		return(h);
	}
}

// prints the tree in treelike fashion
// null nodes are displayed by -1
void treeprinter (int* root)
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		if(i == 0)
			printf("%d",root[0]);
		else
		{
			for(k=0, j=(2*i)-1; k<2*i; j++,k++)
				printf("%d ",root[j]);
		}
		puts("");
	}
}

void delete(int* root,int index)
{
		// when the node is a leaf
		if( *(root + 2*(index + 1)-1) == -1 && *(root + 2*(index + 1)) == -1)
		{
			*(root + index) = -1;
			return ;
		}
		
		else if(*(root + 2*(index + 1)) != -1 && *(root + 2*(index + 1)+1) == -1)
		{
			
			// copy the value of leftchild in the root
			*(root + index) = *(root + 2*(index + 1));
			// delete leftchild
			*(root + 2*(index + 1)) = -1;
			return;
		}
		// does the same for right subtree
		else if(*(root + 2*(index + 1)) == -1 && *(root + 2*(index + 1)+1) != -1)
		{
			// copy the value of right in the root
			*(root + index) = *(root + 2*(index + 1)+1);
			// delete right
			*(root + 2*(index + 1)+1) = -1;
		}
		// when both the nodes connected to the root are not null we find its inorder successor
		// and copy the value of the succesor in the node and delete the successor
		else
		{
			// find successor
			int succr = successor(root,index);	
			// copy its value		
			*(root + index) = *(root + succr);
			// delete it
			*(root + succr) = -1;
			return;
		}
}

// finding inorder successor is 
//finding the next smallest node whose value is just greater than the node
int successor(int* root,int index)
{
	int succr = 2*(index+1);
	
	while(*(root + succr + 2*(succr+1) -1) != -1)
		succr = 2*(succr+1) -1;
		
	return succr;
}
