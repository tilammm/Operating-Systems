#include <stdio.h>
#include <stdlib.h>
 

typedef struct node
{
    int data;
    struct node *next;
} Node;
 
void insert_node(Node * head, int val)
{
    Node * current = head;
    while (current->next != NULL) {
        current = current->next;
    }


    current->next = malloc(sizeof(Node));
    current->next->data = val;
    current->next->next = NULL;
}
 
void delete_node(Node * head)
{
    if (head->next == NULL) {
	   return;
    }


    Node * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
void print_list(Node * head) {
      Node *ptr = head->next;
      while(ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
   }
	printf("\n");
	
} 

int main()
{
    Node * head = malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    insert_node(head, 7);
    print_list(head);
    insert_node(head, 1);
    print_list(head);
    insert_node(head, 3);
    print_list(head);
    insert_node(head, 2);
    print_list(head);
 
    
    print_list(head);
    delete_node(head);
    print_list(head);
    return 0;
}