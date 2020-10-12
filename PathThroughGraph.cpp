#include<iostream>
#include<algorithm>
#include<vector>
#define temp 0
#define per 1
#define NIL -1
#define infinity 99999
using namespace std;
int v,**adj,ch;
int *state,*predecessor,*pathLength,*arr;
int getIndex(int n,int val)
{
	for(int i=0;i<n;i++)
	if(arr[i]==val)
	return i;
	
	return -1;
}
int minTemp()
{
	int min=infinity,k=NIL;
	for(int i=0;i<v;i++)
	{
		if(pathLength[i]<min&&state[i]==temp)
		{
			min=pathLength[i];
			k=i;
		}
	}
	return k;
}
void dijkstra(int s)
{
	state=new int[v];
	predecessor=new int[v];
	pathLength=new int[v];
	for(int i=0;i<v;i++)
	{
		state[i]=temp;
		predecessor[i]=NIL;
		pathLength[i]=infinity;	
	}
	pathLength[s]=0;
	while(1)
	{
		int min=minTemp();
		if(min==NIL)
		return;
		state[min]=per;
		for(int i=0;i<v;i++)
		{
			if(adj[min][i]!=0&&state[i]==temp)
				if(pathLength[min]+adj[min][i]<pathLength[i])
				{
					predecessor[i]=min;
					pathLength[i]=pathLength[min]+adj[min][i];
				}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  long int n1,n2,temp1,i,index=0;
  int v1[100],size1;
  int v2[100],size2;
  cin>>n1>>n2;
  temp1=n1;
  long int div=2;
  v1[index]=n1;
  index+=1;
  while(temp1>0)
  {
    for(i=div;i<=temp1/2;i++)
      if(temp1%i==0)
      {
        temp1/=i;
        v1[index]=temp1;
        index+=1;
        break;
      }
    if(i==((temp1/2)+1))
      break;
  }
  v1[index]=1;
  index+=1;
  size1=index;
  index=0;
  temp1=n2;
  v2[index]=n2;
  index+=1;
  while(temp1>0)
  {
      for(i=div;i<=temp1/2;i++)
      if(temp1%i==0)
      {
        temp1/=i;
        v2[index]=temp1;
        index+=1;
        break;
      }
    if(i==((temp1/2)+1))
      break; 
  }
  v2[index]=1;
  index+=1;
  size2=index;
  int n=size1+size2;
  arr=new int[n];
  index=0;
  for(int i=0;i<n;i++)
  {
  	if(i<size1)
  	arr[i]=v1[i];
  	else arr[i]=v2[index++];
  }
  
    int maxEdges,j,origin,destination,w;
	v=n;
	maxEdges=v*(v-1)/2;
	adj=new int*[v];
	for(i=0;i<v;i++)
	adj[i]=new int[v];
	for(i=0;i<v;i++)
	  for(j=0;j<v;j++)
	    adj[i][j]=0;
	    for(i=0;i<size1-1;i++)
	    {
	    	origin=getIndex(n,v1[i]);
	    	destination=getIndex(n,v1[i+1]);
	    	w=1;
	    	adj[origin][destination]=w;
			adj[destination][origin]=w;
		}
		for(i=0;i<size2-1;i++)
	    {
	    	origin=getIndex(n,v2[i]);
	    	destination=getIndex(n,v2[i+1]);
	    	w=1;
	    	adj[origin][destination]=w;
			adj[destination][origin]=w;
		}
		int s=0,d;
			 dijkstra(s);
	 d=getIndex(n,n2);
	 cout<<pathLength[d];
}
