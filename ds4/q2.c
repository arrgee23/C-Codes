#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value;
    struct tree* left,*right;
    int leftcount, rightcount;
}tree;

tree* insert(tree *root, tree* leaf);
tree* make(tree* root);
tree* build();
int height(tree * root);
tree* search(tree* root, int key);
int searchmin(tree* parent, char side, tree* root);
void removenode(tree** root);
void inorder(tree* root);
void preorder(tree* root);
void postorder(tree* root);

int main()
{
    tree * root=NULL;
    int c1,c2,temp;
    do{
        printf("\n1.Insert\n2.Search\n3.Remove\n4.Height\n5.Display\n6.Exit\n>");
        scanf("%d",&c1);
        switch(c1)
        {
            case 1: printf("\nEnter value\n>");
                    scanf("%d",&temp);
                    tree* leaf = build();
                    leaf->value = temp;
                    root=insert(root,leaf);
                    printf("\nInserted\n");
                    break;
                    
            case 2: printf("\nEnter value to search\n>");
                    scanf("%d",&temp);
                    
                    if(search(root,temp) == NULL)
                        printf("\nValue not found.\n");
                    else
                        printf("\nValue found in BST.");
                    break;
                    
            case 3: printf("\nEnter value to remove\n>");
                    scanf("%d",&temp);
                    tree* removed = search(root,temp);
                    if(removed == NULL)
                        printf("\nValue not found.\n");
                    else
                    {
                        removenode(&removed);
                        printf("\nRemoved");
					}
                    break;
                    
            case 4: printf("\nThe height of the tree is %d\n",height(root));
                    break;
                    
            case 5: printf("\n1.PreOrder\n2.Postorder\n3.Inorder\n>");
                    scanf("%d",&c2);
                    switch(c2)
                    {
                        case 1: preorder(root);
                                break;
                        case 2: postorder(root);
                                break;
                        case 3: inorder(root);
                                break;
                    }
        }
    }while(c1!=6);
    return 0;
}

tree* insert(tree *root, tree* leaf)
{
    if(root==NULL)
        root=leaf;
    else
    {
        if(leaf->leftcount<=leaf->rightcount)
        {
            root->left=insert(root->left, leaf);
            root->leftcount++;
        }
        else
        {
            root->right=insert(root->right, leaf);
            root->rightcount++;
        }
    }
    return root;
}

tree* build()
{
    tree *leaf=malloc(sizeof(tree));
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->leftcount=leaf->rightcount=0;
    leaf->value=0;
    return leaf;
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

tree* search(tree* root, int key)
{
    if(root==NULL)
        return NULL;
    else
    {
        if(root->value==key)
            return root;
        else
        {
			// this is AWESOME
            if(search(root->left,key) || search(root->right,key))
                return root;
        }
    }
}

int searchmin(tree* parent, char side, tree* root)
{
    int val;
    if(root->left)
        return searchmin(root,'l',root->left);
    else
        if(root->right)
            return searchmin(root,'r',root->right);
    if(side=='l')
        parent->left=NULL;
    if(side=='r')
        parent->left=NULL;
    val=root->value;
    free(root);
    return val;
}

void removenode(tree** root)
{
   free(*root);
   (*root) = NULL;
}

void inorder(tree* root)
{
    if(root==NULL)
        return;
    if(root->left)
        inorder(root->left);
    printf("\t%d",root->value);
    if(root->right)
       inorder(root->right);
}

void preorder(tree* root)
{
    if(root==NULL)
        return;
    printf("\t%d",root->value);
    if(root->left)
       preorder(root->left);
    if(root->right)
       preorder(root->right);
}

void postorder(tree* root)
{
    if(root==NULL)
        return;
    if(root->left)
       postorder(root->left);
    if(root->right)
       postorder(root->right);
    printf("\t%d",root->value);
}

