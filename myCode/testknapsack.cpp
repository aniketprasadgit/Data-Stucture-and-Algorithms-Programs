#include<stdio.h>
#include<stdlib.h>
int max(int a,int b) 
{
    return (a>b) ? a : b;
}
int main()
{
    int t;
    scanf("%d",t);
    while(t--)
    {
        int n,i,j,W,*q,**m;
    scanf("%d",&n);
    scanf("%d",&W); 
    q=(int*)calloc(n,sizeof(int));
    m=(int**)calloc(n+1,sizeof(int*));
    for(i=0;i<n+1;i++)
    *(m+i)=(int*)calloc(W+1,sizeof(int));    
    for(i=0;i<n;i++)
    scanf("%d",q+i);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
            m[i][j]=0;
            else if(j<q[i-1])
            m[i][j]=m[i-1][j];
            else 
            m[i][j]=max(q[i-1]+m[i][j-q[i-1]],m[i-1][j]);
        }
    }
printf("%d\n",m[n][W]);    
    }
}
