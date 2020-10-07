#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};
void insert_elements(struct node** head, int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node -> data = new_data;
  new_node -> next = (*head);
  (*head) = new_node;
}
void display_list(struct node *node)
{
  while (node!=NULL)
  {
    printf(“%d “, node -> data);
    node = node -> next;
  }
}
void remove_duplicate_elements(struct node *temp)
{
  struct node *ptr1, *ptr2, *duplicate;
  ptr1 = temp;
  while (ptr1 != NULL && ptr1->next != NULL)
  {
    ptr2 = ptr1;
    while (ptr2->next != NULL)
    {
      if (ptr1->data == ptr2->next->data)
      {
        duplicate = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete(duplicate);
      }
      else
        ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}
