/*
	implement singly linked list 
	a)insertion at the beginning and at end and at kth position
	b)delete any node at given postion
	c)reverse all the nodes inthe linked list
	after completion send it to kgpma29005@gmail.com

*/


// 	aditya girish pawate 18MA20054

#include<stdio.h>
#include <stdlib.h>



// A linked list node 
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
 
 
/* Given a reference (pointer to pointer) to the head of a list 
   and an int,  inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
   
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
   
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
} 



/* Given a node prev_node, insert a new node after the given 
   prev_node */
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */ 
    if (prev_node == NULL)  
    {  
       printf("the given previous node cannot be NULL");        
       return;   
    }   
           
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
   
    /* 3. put in the data  */
    new_node->data  = new_data; 
   
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;  
   
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 


/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next  
          of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
   
    /* 6. Change the next of last node */
    last->next = new_node; 
    return;     
} 


/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position) 
{ 
	int i;
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   struct Node* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for(i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if(temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
} 

  
/* Function to print linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d  ", temp->data);     
        temp = temp->next;   
    } 
    printf("\n");	
}


/* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev   = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) 
    { 
        // Store next 
        next  = current->next;   
  
        // Reverse current node's pointer 
        current->next = prev;    
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
}
  
 
int main() 
{ 
   	int num,nd1,nd2,nd3,nd4,position,flag,i;
	
	
	struct Node* head= NULL;
	struct Node* prev;
	prev=head;
	flag=1;
	do
	{
	
	printf("Enter the instruction to be done:\n");
	printf("1.Insert node at the begining\n2.Insert node at the end\n3.Insert node at position k\n");
	printf("4.delete any node at given position\n5.reverse all the nodes in the linked list\n6.Any other key to exit\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:	printf("Enter the new node data to be inserted in the beginning\n");
			scanf("%d",&nd1);
			push(&head,nd1);
			printf("The final list after operation is:");
			printList(head);
			break;
		case 2: printf("Enter the new node data\n");
			scanf("%d",&nd2);
			append(&head,nd2);
			printf("The final list after operation is:");
			printList(head);
			break; 
		case 3: printf("Enter the new node data and position \n");
			scanf("%d %d",&nd3,&nd4);
			prev=head;
			for(i=0;i<nd4-1;i++)
			 prev=prev->next;

			insertAfter(prev,nd3);
			printf("The final list after operation is:");
			printList(head);
			break;
		case 4: printf("Enter the node position to be deleted\n");
    			scanf("%d",&position);
			deleteNode(&head,position);
			printf("The final list after operation is:");
			printList(head);
			break;
		case 5:	reverse(&head);
			printf("The final list after operation is:");
			printList(head);
			break;
		default:flag=0;
			break;
	}
	}while(flag);
		
			
    return 0; 
} 
  






























