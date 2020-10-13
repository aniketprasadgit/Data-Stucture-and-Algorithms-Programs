#include<iostream>
using namespace std;
int main()
{
	long int n,k,top=0,max=0,i,j,count=0;
	long int **arr,*stack,*points;
	cin>>n>>k;
	points=new long int[n];
	stack=new long int[n];
	arr=new long int*[n+1];
	for(i=0;i<=n;i++)
	arr[i]=new long int[n+1];
	for(i=0;i<n;i++)
	cin>>points[i];
	for(i=1;i<=n;i++)
  {
	arr[0][i]=points[i-1];
	arr[i][0]=points[i-1];
  }
  for(i=1;i<n;i++)
  {
  	count=0;
    for(j=i+1;j<=n;j++)
	{
	    if((arr[0][j]-arr[i][0])%k==0)
		{
		   arr[i][j]=arr[0][j];
		   count++;
		}
		else arr[i][j]=0;	
	}
	if(max<count)
	{
	   top=0;
	   stack[top++]=arr[i][0];
	   for( j=i+1;j<=n;j++)
	   if(arr[i][j]!=0)
	   stack[top++]=arr[i][j];
	   max=count;
	}	
  }	
cout<<top<<endl;
for(i=0;i<top;i++)
cout<<stack[i]<<"\n";
}
