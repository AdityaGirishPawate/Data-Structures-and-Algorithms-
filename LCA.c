

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

  int inorderprinting(struct node* root,int q) 
{ 
    if (root != NULL) 
    { 
        inorderprinting(root->left,q);
        inorderprinting(root->right,q);
    } 
} 

int main()
{
 int i,j,n,m,f=0,q=0,p,c;
  struct node* temp;
struct node* s;
	struct node* g;
   struct node* node;
 scanf("%d",&n);
  scanf("%d",&m);
  scanf()
   s=newnode(m);
  node = s; 
    c = s->data;
for(i=1;i<n;i++)
{
  scanf("%d",&m);
   temp=newnode(m);
      if(f==0)
      {
      node->left = temp;
        g=temp;
       f=1;
        }
      else if(f==1)
       {
        node->right = temp;
            p = node->data;
           if(p<c)
            c=p;
           node = g;
            f = 0;
       }
 }

    printf("%d\n",c);

  
      
}
 
