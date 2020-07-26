#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct AVLNode
{
	int value;
	int balfact;
	struct AVLNode *left;
	struct AVLNode *right;
}AVLNode;

AVLNode * insert(AVLNode *,int,int *);
AVLNode * delvalue(AVLNode *,int,int *);
AVLNode * del(AVLNode *,AVLNode *,int *);
AVLNode * balr(AVLNode *,int *);
AVLNode * ball(AVLNode *,int *);
void display(AVLNode *);
void deltree(AVLNode *);

int main()
{
	AVLNode *avl=NULL;
	int h;
	
	// inserts some random numbers to the node
	avl=insert(avl,20,&h);
	avl=insert(avl,6,&h);
	avl=insert(avl,29,&h);
	avl=insert(avl,5,&h);
	avl=insert(avl,12,&h);
	avl=insert(avl,25,&h);
	avl=insert(avl,32,&h);
	avl=insert(avl,10,&h);
	avl=insert(avl,15,&h);
	avl=insert(avl,27,&h);
	
	printf("\n AVL Tree : \n");
	display(avl);
	avl=delvalue(avl,5,&h);
	avl=delvalue(avl,12,&h);
	printf("\n AVL tree after deletion of a node 5 and 12: \n");
	display(avl);
	deltree(avl);

	return 0;
}



// Inserts an element into tree 
struct  AVLNode * insert(AVLNode *root,int value,int *h)
{
	AVLNode *node1,*node2;
	if(!root)
	{
		root=(AVLNode *)malloc(sizeof(AVLNode));
		root->value=value;
		root->left=NULL;
		root->right=NULL;
		root->balfact=0;
		*h=TRUE;
		return(root);
	}
	if(value < root->value)
	{
		root->left=insert(root->left,value,h);
		// If left subtree is higher 
		if(*h)
		{
			switch(root->balfact)
			{
				case 1:
				node1=root->left;
				if(node1->balfact==1)
				{
					printf("\n Right Rotation alond %d. ",root->value);
					root->left=node1->right;
					node1->right=root;
					root->balfact=0;
					root=node1;
				}
				else
				{
					printf("\n Double rotation , left along %d",node1->value);
					node2=node1->right;
					node1->right=node2->left;

					printf(" then right along %d. \n",root->value);
					node2->left=node1;
					root->left=node2->right;
					node2->right=root;

					if(node2->balfact==1)
					root->balfact=-1;
					else
						root->balfact=0;
					if(node2->balfact==-1)
						node1->balfact=1;
					else
						node1->balfact=0;
					root=node2;
				}
				root->balfact=0;
				*h=FALSE;
				break;
			
				case 0:
				root->balfact=1;
				break;
				
				case -1:
				root->balfact=0;
				*h=FALSE;
			}
		}

	}

	if(value > root->value)
	{
		root->right=insert(root->right,value,h);
		/* If the right subtree is higher */
		if(*h)
		{
			switch(root->balfact)
			{
				case 1:
				root->balfact=0;
				*h=FALSE;
				break;
		
				case 0:
				root->balfact=-1;
				break;
		
				case -1:
				node1=root->right;
				if(node1->balfact==-1)
				{
					printf("\n Left rotation along %d. ",root->value);
					root->right=node1->left;
					node1->left=root;
					root->balfact=0;
					root=node1;
				}
				else
				{
					printf("\n Double rotation , right along %d",node1->value);
					node2=node1->left;
					node1->left=node2->right;
					node2->right=node1;
					printf(" then left along %d. \n",root->value);
					root->right=node2->left;
					node2->left=root;
				
					if(node2->balfact==-1)
					root->balfact=1;
				
					else
					root->balfact=0;
          
					if(node2->balfact==1)
					node1->balfact=-1;
					else
					node1->balfact=0;
					root=node2;
				}
				root->balfact=0;
				*h=FALSE;
			}
		}
	}
 
 
	return(root);

}


/* Deletes an item from the tree */
AVLNode * delvalue(AVLNode *root,int value,int *h)
{
   AVLNode *node;
   if(!root)
   {
      printf("\n No such value. ");
      return (root);
   }
   else
   {
      if(value < root->value)
      {
     root->left=delvalue(root->left,value,h);
     if(*h)
       root=balr(root,h);
      }
      else
      {
     if(value > root->value)
     {
        root->right=delvalue(root->right,value,h);
          if(*h)
         root=ball(root,h);
     }
     else
     {
        node=root;
        if(node->right==NULL)
        {
           root=node->left;
           *h=TRUE;
           free(node);
        }
        else
        {
          node->right=del(node->right,node,h);
          if(*h)
         root=ball(root,h);
        }
      }
    }
      }

   return(root);
 }


 AVLNode * del(AVLNode *succ,AVLNode *node,int *h)
 {
    AVLNode *temp=succ;
    if(succ->left!=NULL)
    {
       succ->left=del(succ->left,node,h);
       if(*h)
      succ=balr(succ,h);
    }
    else
    {
       temp=succ;
       node->value=succ->value;
       succ=succ->right;
       free(temp);
       *h=TRUE;
    }
     return(succ);
}


/* Balance the tree , if right subtree is higher */
AVLNode * balr(AVLNode *root,int *h)
{
   AVLNode *node1,*node2;
   switch(root->balfact)
   {
     case 1:
    root->balfact=0;
    break;
     case 0:
    root->balfact=-1;
    *h=FALSE;
    break;
     case -1:
    node1=root->right;
    if(node1->balfact <= 0)
    {
      printf("\n Left rotation along %d. ",root->value);
      root->right=node1->left;
      node1->left=root;
      if(node1->balfact==0)
      {
          root->balfact=-1;
          node1->balfact=1;
        *h=FALSE;
      }
      else
      {
          root->balfact=node1->balfact=0;
      }
      root=node1;
    }
     else
     {
       printf("\n Double rotation , right along %d ",node1->value);
       node2=node1->left;
       node1->left=node2->right;
       node2->right=node1;
       printf(" then left along %d. \n",root->value);
       root->right=node2->left;
       node2->left=root;

       if(node2->balfact==-1)
      root->balfact=1;
       else
      root->balfact=0;
       if(node2->balfact==1)
     node1->balfact=-1;
       else
     node1->balfact=0;
       root=node2;
       node2->balfact=0;
    }
}
  return (root);
}


/* Balances the tree , if the left subtree is higher */
AVLNode * ball(AVLNode * root,int *h)
{
   AVLNode *node1,*node2;
   switch(root->balfact)
   {
      case -1:
     root->balfact=0;
     break;
      case 0:
     root->balfact=1;
     *h=FALSE;
     break;
      case 1:
     node1=root->left;
     if(node1->balfact >= 0)
     {
         printf("]n Right rotation along %d. ",root->value);
         root->left=node1->right;
         node1->right=root;
         if(node1->balfact==0)
         {
        root->balfact=1;
        node1->balfact=-1;
        *h=FALSE;
         }
         else
         {
           root->balfact=node1->balfact=0;
         }
         root=node1;
     }
     else
       {
      printf("\n Double rotation , left along %d ",node1->value);
      node2=node1->right;
      node1->right=node2->left;
      node2->left=node1;
      printf(" then right along %d .\n",root->value);

      root->left=node2->right;
      node2->right=root;

      if(node2->balfact==1)
          root->balfact=-1;
      else
          root->balfact=0;

      if(node2->balfact==-1)
          node1->balfact=1;
      else
          node1->balfact=0;
      root=node2;
      node2->balfact=0;
       }
    }
    return (root);
}


/*n Displays the tree in-order */
void display(AVLNode *root)
{
  if(root!=NULL)
  {
    display(root->left);
    printf("%d\t",root->value);
    display(root->right);
  }
}


/* Deletes the tree */
void deltree(AVLNode * root)
{
   if(root!=NULL)
   {
    deltree(root->left);
    deltree(root->right);
   }
   free(root);
}
