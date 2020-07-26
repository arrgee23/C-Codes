#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct tree
{
	struct tree *left;
	int value;
	struct tree *right;
}tree;

void treeprinter (tree* root);
void print(tree* root);
tree* search(tree* root,int n);
void insert(tree** root,int n);
void postorder(tree* root);
void preorder(tree* root);
void inorder(tree* root);
bool delete(tree** root,int n);
int height(tree *root);
tree* freemem(tree* node);
tree** successor(tree* node);


int main()
{
	tree* root = NULL;
	while(1)
	{
		int n;
		printf("1. insert\n2. search\n3. print Pre-order\n4. print post-order\n5. print In-order\n6. height\n7. delete\n8. exit\n\tCOMMAND: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: {
						printf("\nEnter number to insert: ");
						int k;
						scanf("%d",&k);
						insert(&root,k);
						break;
					}
					
			case 2: {
						printf("\nEnter number to search: ");
						int m;
						scanf("%d",&m);
						if(search(root,m))
							printf("\nFOUND\n");
						else
							printf("\nDOES NOT  EXIST\n");
						break;
					}
					
			case 3: preorder(root);puts("");break;
			
			case 4: postorder(root);puts("");break;
			
			case 5: inorder(root);puts("");break;
			
			case 6: printf("\nThe height of the tree is = %d\n",height(root));break;
			
			case 7: {
						printf("\nEnter number to delete: ");
						int m;
						scanf("%d",&m);
						if(delete(&root,m))
							printf("\nDELETED\n");
						else
							printf("\nDOES NOT  EXIST\n");
						break;
					}
					
			case 8: return 0;
			
			default: printf("\nInvalid input");
			
		}					
	}
}

tree* search(tree* root,int n)
{	
	// takes care of the case of an empty tree
	if(root == NULL)
		return root;
	
	else
	{	
		if(root -> value == n)
			return root;
	
		else if(root -> left != NULL || root -> right != NULL)
		{
			if(root -> value < n)
				search(root -> right,n);
			else
				search(root -> left,n);
		}
	
		else 
			return NULL;
	}
}


/* inserts a new node in a binary search tree */
void insert ( tree **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = malloc ( sizeof ( tree ) ) ;
		( *sr ) -> left = NULL ;
		( *sr ) -> value = num ;
		( *sr ) -> right = NULL ;
	}
	else /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> value )
			insert ( &( ( *sr ) -> left ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> right ), num ) ;
	}
}

/**
	postorder traversal
	1. traverse left subtree
	2. traverse right subtree
	3. visit root
*/
void postorder(tree* root)
{
	if(root != NULL)
	{
		if(root -> left != NULL)
			postorder(root -> left);
		if(root -> right != NULL)
			postorder(root -> right);
			
		printf("%d ",root -> value);
	}
}

/**
	preorder traversal
	1. visit root
	2. traverse left subtree
	3. traverse right subtree
*/
void preorder(tree* root)
{
	if(root != NULL)
	{
		printf("%d ",root -> value);
		
		if(root -> left != NULL)
			preorder(root -> left);
		if(root -> right != NULL)
			preorder(root -> right);
			
	}
}
/**
	1. Traverse left subtree
	2. Visit the root
	3. Traverse right subtree
*/

void inorder(tree* root)
{
	if(root != NULL)
	{
		if(root -> left != NULL)
			inorder(root -> left);
		
		printf("%d ",root -> value);
		
		if(root -> right != NULL)
			inorder(root -> right);
			
	}
}

bool delete(tree** root,int n)
{
	// searches for the node to be deleted recursively
	if((*root) == NULL)
		return false;
	
	else if((*root) -> value < n)
		return delete(&((*root) -> right), n);
	
	else if((*root) -> value > n)
		return delete(&((*root) -> left), n);
	
	// now if the node exists the pointer to the pointer of the node is stored as root
	else
	{
		// when the node is a leaf
		if((*root) -> left == NULL && (*root) -> right == NULL)
		{
			*root = freemem(*root);
			return true;
		}
		
		else if((*root) -> left != NULL && (*root) -> right == NULL)
		{
			// remember the left tree of the root
			tree* temp = (*root) -> left;
			
			//  free root and set it to null
			*root = freemem(*root);
			//  now rewire root  as left subtree of root
			*root = temp;
			return true;
		}
		// does the same for right subtree
		else if((*root) -> left == NULL && (*root) -> right != NULL)
		{
			tree* temp = (*root) -> right;
			
			*root = freemem(*root);
			
			*root = temp;
			return true;
		}
		// when both the nodes connected to the root are not null we find its inorder successor
		// and copy the value of the succesor in the node and delete the successor
		else
		{
			// find successor
			tree** succr = successor(*root);			
			// copy its value to root
			(*root) -> value = (*succr) -> value;
			*succr = freemem(*succr);
			return true;
		}
	}
}

int height(tree *p)
{
	if(p == NULL)
		return 0;
	else
	{
		int h,lh,rh;
		h=lh=rh=0;
		
		// calculates height of the left subtree
		if(p->left!=NULL)
			lh=(1+height(p->left));
			
		// calculates height of the right subtree
		else if(p->right!=NULL)
			rh=(1+height(p->right));
		
		//returns the bigger number	
		h = lh>rh ? lh:rh;
		return(h);
	}
}
/* 
 * takes a pointer to the node
 * frees that particular node 
 * sets the pointer to null
 * helper function for delete
*/

tree* freemem(tree* node)
{
	free(node);
	return NULL;
}

// finding inorder successor is 
//finding the next smallest node whose value is just greater than the node
tree** successor(tree* node)
{
	tree** succr = &(node -> right);
	
	while((*succr) -> left != NULL)
		*succr = (*succr) -> left;
		
	return succr;
}
