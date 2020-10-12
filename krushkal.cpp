#include<iostream>
#define temp 0
#define per 1
#define NIL -1
#define infinity 99999
using namespace std;
int v,**adj,ch,e=0,count=0,*father;
struct edge
{
	int u;
	int v;
	int weight;
};
struct edge *minimumSpanningTreeEdges;
int isPresent(int a,int b)
{
	int i,rootA,rootB;
	while(a!=NIL)
	{
		rootA=a;
		a=father[a];
	}
	while(b!=NIL)
	{
		rootB=b;
		b=father[b];
	}
	if(rootA!=rootB)
	return 1;
	else return 0;
	/*for(i=1;i<=count;i++)
	{
		cout<<"minimumSpanningTreeEdges[i].u => "<<minimumSpanningTreeEdges[i].u<<"minimumSpanningTreeEdges[i].u=> "<<minimumSpanningTreeEdges[i].v<<"\n";
		if(minimumSpanningTreeEdges[i].u==a)
		{
			for(int j=0;j<count;j++)
				if(minimumSpanningTreeEdges[j].u==b||minimumSpanningTreeEdges[j].v==b)
				      return 1;
		}
		if(minimumSpanningTreeEdges[i].v==a)
		{
			for(int j=0;j<count;j++)
				if(minimumSpanningTreeEdges[j].u==b||minimumSpanningTreeEdges[j].v==b)
				      return 1;
		}
		if(minimumSpanningTreeEdges[i].u==b)
		{
			for(int j=0;j<count;j++)
				if(minimumSpanningTreeEdges[j].u==a||minimumSpanningTreeEdges[j].v==a)
				      return 1;
		}
		if(minimumSpanningTreeEdges[i].v==b)
		{
			for(int j=0;j<count;j++)
				if(minimumSpanningTreeEdges[j].u==a||minimumSpanningTreeEdges[j].v==a)
				      return 1;
		}
	}
	return 0;*/
}
void krushkal()
{
	int i,j;
	father=new int[e];
	for(i=0;i<e;i++)
	father[i]=NIL;
		for(i=0;i<e-1;i++)
	{
		for(j=i+1;j<e;j++)
		{
			if(adj[i][2]>adj[j][2])
			{
				int temp1 = adj[i][0];
				int temp2 = adj[i][1];
				int temp3 = adj[i][2];
				adj[i][0]=adj[j][0];
				adj[i][1]=adj[j][1];
				adj[i][2]=adj[j][2];
				adj[j][0]=temp1;
				adj[j][1]=temp2;
				adj[j][2]=temp3;
			}
		}
	}
	minimumSpanningTreeEdges=new struct edge[v];
	for(i=0;i<e;i++)
	{
		int rootA,rootB;
		//int check=isPresent(adj[i][0],adj[i][1]);
		//cout<<i<<"\n";
		//cout<<adj[i][0]<<"   "<<adj[i][1]<<" \n";
		//cout<<check<<"  ";
		int a=adj[i][0];
		int b=adj[i][1];
		while(a!=NIL)
	{
		rootA=a;
		a=father[a];
	}
	while(b!=NIL)
	{
		rootB=b;
		b=father[b];
	}
	if(rootA!=rootB)
	{
		count++;
		minimumSpanningTreeEdges[count].u=adj[i][0];
		minimumSpanningTreeEdges[count].v=adj[i][1];
		minimumSpanningTreeEdges[count].weight=adj[i][2];
		father[rootB]=rootA;
	}
	}
	if(count!=v-1)
	{
		cout<<"Graph is not connected\n";
		//exit(0);
	}
}
void createGraph()
{
    int maxEdges,i,origin,destination,w;
	cout<<"Enter 1 For Undirected Graph or 2 For Directed Graph : ";
	cin>>ch;
	cout<<"Enter The no of vertices : ";
	cin>>v;
	if(ch==1)
	maxEdges=v*(v-1)/2;
	else maxEdges=v*(v-1);
	adj=new int*[maxEdges];
	for(i=0;i<maxEdges;i++)
	adj[i]=new int[3];
	for(i=0;i<maxEdges;i++)
	{
		//cout<<"Enter edge "<<i<<" (-1 -1 to quit) : ";
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
		//	cout<<"Please Enter The Weight Of Edge : ";
	        e++;
			cin>>w;
			adj[i][0]=origin;
			adj[i][1]=destination;
			adj[i][2]=w;
		}
	}	
	
	for(i=0;i<e;i++)
	{
		cout<<adj[i][0]<<"  "<<adj[i][1]<<"  "<<adj[i][2]<<"\n";
	}
}
int main()
{
	 int s,i,weight=0;
     createGraph();	
	 krushkal();
	 for(i=0;i<e;i++)
	 cout<<adj[i][0]<<"  "<<adj[i][1]<<"  "<<adj[i][2]<<"\n";
	 for(i=1;i<v;i++)
	 {
	 	cout<<minimumSpanningTreeEdges[i].u<<"->"<<minimumSpanningTreeEdges[i].v<<" Weight Of Edge : "<<minimumSpanningTreeEdges[i].weight<<"\n";
	 	weight+=minimumSpanningTreeEdges[i].weight;
	 }
	 cout<<"Weight Of Minimum Spanning Tree is : "<<weight<<endl;
}
