#include<stdio.h>
#include<stdlib.h>
int min(int x,int y);
int main()
{
	int **arr,i,n,j,w,temp1,temp2,temp3,amount,cost=0;
	printf("Enter the no of items : ");
	scanf("%d",&n);
    arr=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	*(arr+i)=(int*)calloc(3,sizeof(int));
    printf("Enter the item price :");
    for(i=0;i<n;i++)
    scanf("%d",(*(arr+i)+0));
    printf("Enter the item quantity :");
    for(i=0;i<n;i++)
    {
	   scanf("%d",(*(arr+i)+1));
	   *(*(arr+i)+2)=*(*(arr+i)+0)/(*(*(arr+i)+1));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		printf("%d ",*(*(arr+i)+j));
		printf("\n");
	}
	printf("Enter the weight of bag : ");
	scanf("%d",&w);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(*(arr+i)+2)<*(*(arr+j)+2))
			{
				temp1=*(*(arr+i)+0);
				temp2=*(*(arr+i)+1);
				temp3=*(*(arr+i)+2);
				*(*(arr+i)+0)=*(*(arr+j)+0);
				*(*(arr+i)+1)=*(*(arr+j)+1);
				*(*(arr+i)+2)=*(*(arr+j)+2);
				*(*(arr+j)+0)=temp1;
				*(*(arr+j)+1)=temp2;
				*(*(arr+j)+2)=temp3;
			}
		}
	}
	i=0;
    while(w>0)
    {
    	amount=min(w,*(*(arr+i)+1));
    	w=w-amount;
    	cost+=amount*(*(*(arr+i)+2));
    	i++;
	}
	
	printf("Cost = %d",cost);
	
	/*5
10
20
30
40

30
20
100
90
160*/
}
int min(int x ,int y)
{
	if(x>y)
	return y;
	else return x;
}
