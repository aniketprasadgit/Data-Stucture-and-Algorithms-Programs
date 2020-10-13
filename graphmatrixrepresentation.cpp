#include<iostream>
using namespace std;
int main()
{
	int v,maxEdges,i,j,**adj,ch,origin,destination;
	cout<<"Enter 1 For Undirected Graph or 2 For Directed Graph : ";
	cin>>ch;
	cout<<"Enter The no of vertices : ";
	cin>>v;
	if(ch==1)
	maxEdges=v*(v-1)/2;
	else maxEdges=v*(v-1);
	adj=new int*[v];
	for(i=0;i<v;i++)
	adj[i]=new int[v];
	for(i=0;i<v;i++)
	  for(j=0;j<v;j++)
	    adj[i][j]=0;
	for(i=1;i<maxEdges;i++)
	{
		cout<<"Enter edge "<<i<<" (-1 -1 to quit) : ";
		cin>>origin>>destination;
		if(origin==-1&&destination==-1)
		break;
		if(origin<0||origin>=v||destination<0||destination>=v)
		{
			cout<<"Invalid Vertex! "<<endl;
			i--;
		}
		else
		{
			adj[origin][destination]=1;
			if(ch==1)
			adj[destination][origin]=1;
		}
	}
	cout<<"The Adjanecy Matrix is :"<<endl;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		cout<<adj[i][j]<<" ";
		cout<<endl;
	}
}
