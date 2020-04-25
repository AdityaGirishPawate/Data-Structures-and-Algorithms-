
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
   struct node* left;
  struct node* right;
};

struct node* newnode(int data)
{
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
   temp->data = data;
    temp->left=NULL;
  temp->right=NULL;
   return temp;
}

void preorderprinting(struct node* root)
{
    if(root!=NULL)
  {
    printf("%d\n",root->data);
    preorderprinting(root->left);
    preorderprinting(root->right);
  }

          }

void postorderprinting(struct node* root)
{

if(root!=NULL)
{
  postorderprinting(root->left);
     postorderprinting(root->right);
  printf("%d\n",root->data); 
      }

}
void inorderprinting(struct node* root) 
{ 
    if (root != NULL) 
    { 
        inorderprinting(root->left); 
        printf("%d \n", root->data); 
        inorderprinting(root->right); 
    } 
} 

int main()
{
 int i,j,n,m,f,q;
  struct node* temp;
struct node* s;
	struct node* g;
   struct node* node;
 scanf("%d",&n);
  scanf("%d",&m);
   s=newnode(m);
for(i=1;i<n;i++)
{
  scanf("%d",&m);
   temp=newnode(m);
    node = s;
   while(node!=NULL)
  {
    if(node->data<temp->data)
{
      g = node;
      node = node->right;
      f=0;
}
     else if(node->data>temp->data)
      {
       g=node;
     node = node->left;
     f=1;
  }
  }
  if(f==1)
    g->left = temp;
  else
  g->right=temp;
 }
  
  printf("1:for inorder traversal\n");
  printf("2:for preorder traversal\n");
  printf("3:for postorder traversal\n");
   scanf("%d",&q);
  if(q==1)
   inorderprinting(s);
else if(q==2)
  preorderprinting(s);
 else if(q==3)
  postorderprinting(s);
 
 }
    
