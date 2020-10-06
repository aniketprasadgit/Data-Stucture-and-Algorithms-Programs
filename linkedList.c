// https://www.facebook.com/vishal1427/posts/2644630989087681
// Subscribed by vishal


#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct Node
{
  int data;
  sturct Node* next;
};
void append(struct node**, int);
void display(struct node *);
void main()
{
  struct node *start=NULL:
  clrscr();
  append(&start,10);
  append(&start,20);
  append(&start,30);
  append(&start,40);
  append(&start,50);
  diaplay(start);
  getch();
}
void append(struct node** ps, int x)
{
  struct node *p,*temp;
  p=(struct node*)malloc(sizeof(struct node));
  p->data=x;
  p->next=NULL;
  if(*ps==NULL)
  {
    *ps=p;
    return;
  }
  temp=*ps;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=p;
}

void display(struct node *p)
{
  if(p==NULL)
  {
    printf("List is empty");
    return;
  }
  while(p!=NULL)
  {
    printf("\n %d",p->data);
    p=p->next;
  }
}
