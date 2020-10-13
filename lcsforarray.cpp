#include<iostream>
using namespace std;
char **print;
void display(int i,int j);
int *arr1;
int main()
{ 
int *arr2;
int **arr,i,j,n,m,k=n+1,t=m+1;
cin>>n>>m;
print=new char*[n+1];
for(i=0;i<n+1;i++)
print[i]=new char[m+1];
    arr1=new int[n];
    arr2=new int[m];
	for(i=0;i<n;i++)
	cin>>arr1[i];
	for(i=0;i<m;i++)
	cin>>arr2[i];
	arr=new int*[n+1];
	for(i=0;i<=n;i++)
	arr[i]=new int[m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
			{
				arr[i][j]=0;
				print[i][j]='0';
			}
			else if(arr1[i-1]==arr2[j-1])
			{
			  arr[i][j]=arr[i-1][j-1]+1;
			  print[i][j]='d';	
			}
			else if(arr[i-1][j]>=arr[i][j-1])
			{
				arr[i][j]=arr[i-1][j];
				print[i][j]='u';
			}
			else {
			arr[i][j]=arr[i][j-1];
			print[i][j]='s';
			}    
		}
	}
	display(n,m);
}
void display(int i,int j)
{
	if(i==0||j==0)
	return;
	if(print[i][j]=='d')
	{
		display(i-1,j-1);
		printf("%d ",arr1[i-1]);
	}
	else if(print[i][j]=='u')
	display(i-1,j);
	else display(i,j-1);
}
