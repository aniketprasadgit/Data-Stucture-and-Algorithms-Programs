#include<iostream>
#define temp 0
#define per 1
#define NIL -1
#define infinity 99999
using namespace std;
int v,**adj,ch;
int *state,*predecessor,*pathLength;
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
void path(int s,int d)
{
	if(d==s)
	{
		cout<<s;
		return;
	}
	path(s,predecessor[d]);
	cout<<"->"<<d;
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
void createGraph()
{
    int maxEdges,i,j,origin,destination,w;
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
			cin>>w;
			adj[origin][destination]=w;
			if(ch==1)
			adj[destination][origin]=w;
		}
	}	
}
int main()
{
	 int s,d;
     createGraph();
	 cout<<"Enter Source Vertex : ";
	 cin>>s;	
	 dijkstra(s);
	 for(int i=0;i<v;i++)
	 cout<<pathLength[i]<<"  "<<predecessor[i]<<"  "<<state[i]<<"  \n";
	 while(1)
	 {
	 	cout<<"Enter Destination Vertex(-1 to Quit): ";
	 	cin>>d;
	 	if(d==-1)
	 	break;
	 	if(d>=v||d<0)
	 	cout<<"This Vertex does not exist!\n";
	 	else if(s==d)
	 	cout<<"Source And Destination Are Same!\n";
	 	else if(pathLength[d]==infinity)
	 	cout<<"No path From Source to destination";
	 	else path(s,d);
	 	cout<<"\nShortest Distance is : "<<pathLength[d]<<"\n";
	 }
}
