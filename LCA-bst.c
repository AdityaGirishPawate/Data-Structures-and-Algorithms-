#include<stdio.h>
#include<stdlib.h>
struct node{
		int data;
		struct node* left;
		struct node* right;
};
void bst_insert (struct node* root, int newdata)
{
	if (root->data>=newdata)
	{
		if (root->left==NULL)
		{
			struct node* new_node=(struct node*) malloc (sizeof(struct node));
			new_node->data=newdata;
			new_node->left=new_node->right=NULL;
			root->left=new_node;
			return;
		}
		else
		{
			bst_insert (root->left, newdata);
			return;
		}
	}
	else
	{
		if (root->right==NULL)
		{
			struct node* new_node=(struct node*) malloc (sizeof(struct node));
			new_node->data=newdata;
			new_node->left=new_node->right=NULL;
			root->right=new_node;
			return;
		}
		else
		{
			bst_insert (root->right, newdata);
			return;
		}
	}
}
void build_bst (struct node** head, int newdata)
{
	struct node* temp;
	temp=(*head);
	if (temp==NULL)
	{
		struct node* new_node=(struct node*) malloc (sizeof(struct node));
		new_node->data=newdata;
		new_node->left=new_node->right=NULL;
		*head=new_node;
		return;
	}
	else
	{
		bst_insert (temp, newdata);
		return;
	}
}
void inorder (struct node* root)
{
	if (root==NULL)
		return;
	inorder (root->left);
	printf ("%d  ",root->data);
	inorder (root->right);
	return;
}
struct node* lca (struct node* root, int p, int q)
{
	struct node* ancestor;
	if ((p<=root->data) && (q<=root->data))
	{
		ancestor=lca (root->left, p, q);
		return ancestor;
	}
	else if ((p>root->data) && (q>root->data))
	{
		ancestor=lca (root->right, p, q);
		return ancestor;
	}
	else
		return root;
}
int main()
{
	struct node* header=NULL;
	struct node* ancestor;
	int opt, newdata, p, q;
	opt=5;
	while (opt)
	{
		printf("\n1. enter en element into the tree\n2. inorder\n3. find lowest common ancestor of two numbers in the tree\n0. end of program\n\nchoose one option: ");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("enter the number: ");
			scanf("%d",&newdata);
			build_bst (&header, newdata);
			continue;
		}
		if(opt==2)
		{
			printf("the inorder traversal is:\t");
			inorder (header);
			continue;
		}
		if(opt==3)
		{
			printf("the tree elements are:\t\t");
			inorder (header);
			printf("\nenter the two node numbers from this list:\n");
			scanf("%d",&p);
			scanf("%d",&q);
			ancestor=lca (header, p, q);
			printf("the ancestor of %d and %d is %d.", p, q, ancestor->data);
			continue;
		}
		if(opt==0)
			printf("end of program\n");
	}
	return 0;
}
