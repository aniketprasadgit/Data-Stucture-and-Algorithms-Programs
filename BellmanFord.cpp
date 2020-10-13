#include<iostream>
#define temp 0
#define per 1
#define NIL -1
#define infinity 99999
using namespace std;
int v,**adj,ch;
int *queue,*state,*predecessor,*pathLength,front=-1,rear=-1;
void insertQueue(int data)
{
	if(front==-1)
	front=0;
	rear++;
	queue[rear]=data;
}
int deleteQueue()
{
	int ans=queue[front];
	front++;
	return ans;
}
int isEmptyQueue()
{
	if(front==-1||front>rear)
	return 1;
	else return 0;
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
int BellmanFord(int s)
{
	int k=0;
	state=new int[v];
	predecessor=new int[v];
	pathLength=new int[v];
	queue=new int[v];
	for(int i=0;i<v;i++)
	{
		state[i]=temp;
		predecessor[i]=NIL;
		pathLength[i]=infinity;	
	}
	insertQueue(s);
	pathLength[s]=0;
	state[s]=per;
	while(!isEmptyQueue())
	{
		int current = deleteQueue();
		state[current]=temp;
		if(s==current)
	    k++;
		if(k>=v)
		return -1;	
		for(int i=0;i<v;i++)
		{
			if(adj[current][i]!=0&&pathLength[current]+adj[current][i]<pathLength[i])
			{
				pathLength[i]=pathLength[current]+adj[current][i];
				predecessor[i]=current;
				if(state[i]==temp)
				{
					insertQueue(i);
					state[i]=per;
				}
			}
		}
	}
		return 1;
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
	 int s,d,check;
     createGraph();
	 cout<<"Enter Source Vertex : ";
	 cin>>s;	
	 check=BellmanFord(s);
	 if(check==-1)
	 {
	 	cout<<"Negative Cycle Found!";
	 	exit(0);
	 }
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
