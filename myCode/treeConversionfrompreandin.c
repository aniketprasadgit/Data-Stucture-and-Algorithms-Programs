#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	char data;
	struct node* right;
};
int index=0;
struct node *tree(char* pre, char* in,int lower,int upper)
{
	struct node *temp;
	int j,mid;
	if(lower>upper)
	return NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=pre[index];
	//printf("temp->data = %c\n",temp->data );
	for(j=lower;j<=upper;j++)
	if(in[j]==pre[index])
	break;
	index++;
	mid=j;
	if(lower==upper)
	{
	temp->left=NULL;
	temp->right=NULL;
	return temp;
	}

	//printf("%d\n",mid);
	temp->left=tree(pre,in,lower,mid-1);
	temp->right=tree(pre,in,mid+1,upper);
	return temp;
}
void display(struct node* root)
{
	if(root==NULL)
	return;
	display(root->left);
	display(root->right);
    printf("%c ",root->data);
}
int main()
{
	char pre[]={'A','B','D','G','H','E','I','C','F','J','K'};
	char  in[]={'G','D','H','B','E','I','A','C','J','F','K'};
//	char *arr1,*arr2;
	struct node* root;
/*	int length,i;
	printf("Enter the size of an array : ");
	scanf("%d",&length);
	arr1=malloc(sizeof(char*) * length);
	arr2=malloc(sizeof(char*) * length);
	printf("Enter the preorder traversal of tree :");
	for(i=0;i<length;i++)
	scanf("%c",&arr1[i]);
	printf("Enter the Inorder traversal of tree :");
	for(i=0;i<length;i++)
	scanf("%c",&arr2[i]);*/
	root=tree(pre,in,0,10);
	printf("Postorder of given tree :");
	display(root);
}
