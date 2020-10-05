//https://www.facebook.com/Ashi.Sk99/posts/1430832100447900
//subscribed by Code House
//LinkedList implement
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
   struct NODE{
        
        int num;
        
        struct NODE *leftptr;
        struct NODE *rightptr;


       };
       typedef struct NODE node;
       node *head,*last,*temp;
       last=0;
       int choice=1;
       int count=0;
       last=0;
       while(choice==1){
       

     temp=(node *)malloc(sizeof(node));
     printf("Enter the Data: \n");
     scanf("%d",&temp->num);
     if(last==0){
         last=head=temp;
         temp->leftptr=0;

     }
     else{
         temp->leftptr=last;
         last->rightptr=temp;
         last=temp;
     }
     printf("\nPress 1 for continue or Press any key other key to exit:\n");
     scanf("%d",&choice);
       }
       //print the entered data in forward way
     last->rightptr=0;
     temp=head;
     printf("\nPrint in forward way :  \n");
     while(temp !=0){
         printf("[ %d ] =>",temp->num);
         count++;
         temp=temp->rightptr;
     }

         //print the entered data in reverse way
     
     temp=last;
     printf("\nPrint in reverse way :  \n");
     while(temp !=0){
         printf("[ %d ] =>",temp->num);
         count++;
         temp=temp->leftptr;
     }

}