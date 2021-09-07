#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void print_list(struct Node *head){
  while(head!=NULL){
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}


void insert_node(struct Node* previous_node, int new_data){

  //Check if the node after which we want to insert really exists
  if(previous_node==NULL){
    return;
  }
 
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = new_data;
  
  new_node->next = previous_node->next;
 
  previous_node->next = new_node;
}


void delete_node(struct Node** head, int key){
  
  struct Node *temp = *head;
  struct Node *previous_node;

  //Delete head itself
  if(temp!=NULL && temp->data==key){
    *head = temp->next;
    free(temp);
    return;
  }
 
  
  //Delete node at the end or between other 2 nodes
  while(temp!=NULL && temp->data!=key){
    previous_node = temp;
    temp = temp->next;
  }
 
  //If we cant find node with such data
  if (temp == NULL)
    return;
  
  previous_node->next = temp->next;

  free(temp);
}


int main() {
  
  struct Node *head = (struct Node*)malloc(sizeof(struct Node));
  head->data=0;
  
  insert_node(head, 7);
  insert_node(head, 6);
  insert_node(head, 5);
  insert_node(head, 4);
  insert_node(head, 3);
  insert_node(head, 2);
  insert_node(head, 1);

  printf("Linked list: ");
  print_list(head);

  delete_node(&head,0);
  delete_node(&head,7);
  
  printf("Linked list: ");
  print_list(head);
  
  return 0;
}
