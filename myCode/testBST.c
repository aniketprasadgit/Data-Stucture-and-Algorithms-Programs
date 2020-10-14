#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<malloc.h>
struct node
{
	struct node *leftChild;
	int data;
	struct node *rightChild;
};
void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int height(struct node* root)
{
	int leftHeight,rightHeight;
	if(root==NULL)
	return 0;
	leftHeight=height(root->leftChild)
	rightHeight=height(root->rightChild)
	if(leftHeight>rightheight)
	return 1 + leftHeight;
	else return 1 + rightHeight; 
}
struct node *search(struct node* ptr,int data)
{
	if(ptr==NULL)
	return NULL;
	if(ptr->data==data)
	return ptr;
	else if(ptr->data>data)
	 search(ptr->leftChild,data);
	else search(ptr->rightChild,data);
}
struct node* create()
{
	struct node *temp,*root,*temp2,*parent;
	root=NULL;
	int x=1,count=1,ch=1;
	do
	{
		printf("Enter The Element Which You Want To Insert At node %d :",count);
		scanf("%d",&x);
		temp=(struct node*)malloc(sizeof(struct node));
			temp->data=x;
            temp->rightChild=NULL;
			temp->leftChild=NULL;
			if(search(root,x)==NULL)
			{
				count++;
			   if(root==NULL)
			   root=temp;
			   else
			   {   temp2=root;
			   	   while(temp2!=NULL)
			   	   {
			   	   	  parent=temp2;
			   	      if(temp2->data>x)
					  temp2=temp2->leftChild;
					  else
			   	 	  temp2=temp2->rightChild;
					}
					if(parent->data>x)
					parent->leftChild=temp;
					else parent->rightChild=temp;
			   }
			   printf("Element Are Inserted at %d node : \n",count);
               printf("Press 1 For Create Another Node Or 0 For Not (1/0) :");
			   scanf("%d",&ch);	
			    system("cls");
			}
			else printf("Duplicate Element not allowed in BST!\n");		
			
		if(ch!=1&&ch!=0)
        {
           printf("Enter The Coorect option : \n");
           printf("Press 1 For Create Another Node Or 0 For Not Create Another Node (1/0) : ");
           scanf("%d",&ch);
           system("cls");
        }	
	}while(ch==1);
	return root;
}
void insert(struct node* root,int element)
{
	struct node *temp,*temp2,*parent;
	if(search(root,element)==NULL)
	{
		    temp=(struct node*)malloc(sizeof(struct node));
			temp->data=element;
            temp->rightChild=NULL;
			temp->leftChild=NULL;
			
			   if(root==NULL)
			   root=temp;
			   else
			   {   
			       temp2=root;
			   	   while(temp2!=NULL)
			   	   {
			   	   	  parent=temp2;
			   	      if(temp2->data>element)
					  temp2=temp2->leftChild;
					  else
			   	 	  temp2=temp2->rightChild;
					}
					if(parent->data>element)
					parent->leftChild=temp;
					else parent->rightChild=temp;
			   }	
	}
}
void display(struct node* root)
{
	if(root==NULL)
	return;
	printf("%d ",root->data);
	display(root->leftChild);
	display(root->rightChild);
}
struct node* caseA(struct node* root,struct node* parent,struct node* temp)
{
	if(parent==NULL)
	root=NULL;
	else if(parent->leftChild==temp)
	parent->leftChild=NULL;
	else parent->rightChild=NULL;
	free(temp);
	return root;
}
struct node* caseB(struct node* root,struct node* parent,struct node* temp)
{
	if(parent==NULL)
	root= NULL;
	else if(parent->leftChild==temp)
	{
		if(temp->leftChild!=NULL)
		parent->leftChild=temp->leftChild;
		else parent->leftChild=temp->rightChild;
	}
	else
	{
        if(temp->leftChild!=NULL)
		parent->rightChild=temp->leftChild;
		else parent->rightChild=temp->rightChild;
	}
	free(temp);
	return root;
}
struct node* caseC(struct node* root,struct node* parent,struct node* temp)
{
	struct node *ptr,*par;
	ptr=temp->rightChild;
	par=temp;
	while(ptr->leftChild!=NULL)
	{
	  par=ptr;	
	  ptr=ptr->leftChild;	
	}
	temp->data=ptr->data;
	if(ptr->rightChild==NULL)
	root=caseA(root,par,ptr);
	else root=caseB(root,par,ptr);
	
	return root;
}
struct node* del(struct node* root,int element)
{
	struct node* parent,*temp;
	temp=root;
	if(search(root,element)!=NULL)
	{
		while(temp->data!=element)
		{
			parent=temp;
			if(element<temp->data)
			temp=temp->leftChild;
			else temp=temp->rightChild;
		}
		if(temp->leftChild!=NULL&&temp->rightChild!=NULL)
		root=caseC(root,parent,temp);
		else if(temp->leftChild==NULL&&temp->rightChild==NULL)
		root=caseA(root,parent,temp);
		else if(temp->leftChild!=NULL||temp->rightChild!=NULL)
		root=caseB(root,parent,temp);
	}
	else printf("Element not Found!");
	return root;
}
int main()
{
	struct node* root;
	int choice,data;
	while(1)
	{
		printf("\n\n\n\n");
printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*        ---  Binary Search Tree  ---               *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*      (1) For Create Binary Search Tree            *\n");
printf("\t\t*      (2) For Insert Element In BST                *\n");
printf("\t\t*      (3) For Delete Element In BST                *\n");
printf("\t\t*      (4) For Search Element In BST                *\n");
printf("\t\t*      (5) Preorder Traversal Of BST                *\n");
printf("\t\t*      (6) Inorder Traversal Of BST                 *\n");
printf("\t\t*      (7) PostOrder Traversal Of BST               *\n");
printf("\t\t*      (8) for exit.....                            *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        gotoxy(40,18);
        scanf("%d",&choice);
        system("cls");
         switch(choice)
        {
            case 1: root=create();
                    break;
            case 2: printf("Enter The Element Which You Want Insert : ");
            		scanf("%d",&data);
            		insert(root,data);
            		break;
            case 3: printf("Enter The Element Which You Want Delete : ");
            		scanf("%d",&data);
            		root=del(root,data);
            		break;
            case 5: printf("Preorder traversal of BST : ");
	                display(root);
	                system("pause");
            	    system("cls");
            	    break;
            case 8: printf("thank you......\n\n\n\n\n\n\n");
					       exit(0);
            default : printf("please enter correct choice:\n");
            		         system("pause");
            		         system("cls");
        }
	}
}
