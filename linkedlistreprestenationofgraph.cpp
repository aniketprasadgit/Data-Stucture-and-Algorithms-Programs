#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
struct vertex;
void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
struct edge
{
	struct vertex *destinationVertex;
	struct edge *nextEdge;
};
struct vertex
{
	int data;
	struct vertex *nextVertex;
	struct edge *firstEdge;
}*start=NULL;
void insertVertex(int v)
{
	struct vertex *temp,*ptr;
	temp=new struct vertex;
	temp->data=v;
	temp->nextVertex=NULL;
	temp->firstEdge=NULL;
	if(start==NULL)
	{
	   start=temp;
	   cout<<"Vertex is Inserted!\n";
	   return;	
	}
	ptr=start;
	while(ptr->nextVertex!=NULL)
	ptr=ptr->nextVertex;
	ptr->nextVertex=temp;	
    cout<<"Vertex is Inserted!\n";
}
void deleteVertex(int v)
{
	struct vertex *ptr,*tempVertex;
	struct edge *ptrEdge,*tempEdge;
	if(start==NULL)
	{
		cout<<"No Vertex to Deleted!\n";
		return;
	}
	if(start->data==v)
	{
		tempVertex=start;
		start=start->nextVertex;
	}
	else
	{
		ptr=start;
		while(ptr->nextVertex!=NULL)
		{
			if(ptr->nextVertex->data==v)
			break;
			ptr=ptr->nextVertex;
		}
		if(ptr->nextVertex==NULL)
		{
			cout<<"Vertex Not Found!\n";
			return;
		}
		else 
		{
			tempVertex=ptr->nextVertex;
			ptr->nextVertex=tempVertex->nextVertex;
		}
	}
	ptrEdge=tempVertex->firstEdge;
	while(ptrEdge!=NULL)
	{
		tempEdge=ptrEdge;
		free(tempEdge);
		ptrEdge=ptrEdge->nextEdge;
	}
	free(tempVertex);
	cout<<"Vertex and All its Edges Deleted\n";
}
struct vertex *findVertex(int u)
{
     struct vertex *ptr;
     ptr=start;
	 while(ptr!=NULL)
	 {
	    if(ptr->data==u)
		return ptr;
		ptr=ptr->nextVertex;	
	 }
	 return NULL;	
}
void insertEdge(int u,int v)
{
	struct vertex *locu,*locv;
	struct edge *temp,*ptr;
	locu=findVertex(u);
	locv=findVertex(v);
	if(locu==NULL)
	{
		cout<<"Origin Vertex Not Present, First Insert "<<u<<"Vertex \n";
		return;
	}
	if(locv==NULL)
	{
		cout<<"Destination Vertex Not Present, First Insert "<<v<<"Vertex \n";
		return;
	}
	temp=new struct edge;
	temp->nextEdge=NULL;
	temp->destinationVertex=locv;
	if(locu->firstEdge==NULL)
	locu->firstEdge=temp;
	else
	{
		ptr=locu->firstEdge;
		while(ptr->nextEdge!=NULL)
		ptr=ptr->nextEdge;
		ptr->nextEdge=temp;
	}
	cout<<"Edge Inserted\n";
}
void deleteEdge(int u,int v)
{
	struct vertex *locu;
	struct edge *temp,*ptr;
	locu=findVertex(u);
	if(locu==NULL)
	{
		cout<<"Origin Vertex Not Present, First Insert "<<u<<"Vertex \n";
		return;
	}
	if(locu->firstEdge==NULL)
	{
		cout<<"Edge Not Present\n";
		return;
	}
	if(locu->firstEdge->destinationVertex->data==v)
	{
		temp=locu->firstEdge;
		locu->firstEdge=temp->nextEdge;
		free(temp);
		cout<<"Edge Deleted\n";
		return;
	}
	ptr=locu->firstEdge;
	while(ptr->nextEdge!=NULL)
	{
		if(ptr->nextEdge->destinationVertex->data==v)
		{
		temp=ptr->nextEdge;
		ptr->nextEdge=temp->nextEdge;
		free(temp);
		cout<<"Edge Deleted\n";
		return;
		}
		ptr=ptr->nextEdge;
	}
	cout<<"This Edge Not Present In The Graph\n";
}
void display()
{
	struct vertex *ptrVertex;
	struct edge *ptrEdge;
	ptrVertex=start;
	while(ptrVertex!=NULL)
	{
		cout<<ptrVertex->data<<" ";
		if(ptrVertex->firstEdge!=NULL)
		{
			ptrEdge=ptrVertex->firstEdge;
			while(ptrEdge!=NULL)
			{
				cout<<ptrEdge->destinationVertex->data<<" ";
				ptrEdge=ptrEdge->nextEdge;
			}
		}
		cout<<"\n";
		ptrVertex=ptrVertex->nextVertex;
	}
}
void deleteIncomingEdges(int u)
{
	struct vertex *ptr;
	struct edge *ptrEdge,*temp;
	ptr=start;
	if(start==NULL)
	return;
	while(ptr!=NULL)
	{
		if(ptr->firstEdge==NULL)
		{
		  ptr=ptr->nextVertex;
		  continue;	
		}
		if(ptr->firstEdge->destinationVertex->data==u)
		{
			temp=ptr->firstEdge;
			ptr->firstEdge=temp->nextEdge;
			free(temp);
			continue;
		}
		ptrEdge=ptr->firstEdge;
		while(ptrEdge->nextEdge!=NULL)
		{
			if(ptrEdge->nextEdge->destinationVertex->data==u)
			{
			temp=ptrEdge->nextEdge;
			ptrEdge->nextEdge=temp->nextEdge;
			free(temp);
			continue;
			}
			ptrEdge=ptrEdge->nextEdge;
		}
		ptr=ptr->nextVertex;
	}
	cout<<"All Incoming Edges Are Deleted\n";
}
int main()
{
	int choice,data,origin,destination;;
	while(1)
	{
		printf("\n\n\n\n");
printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*        ---  Graph Data Structure  ---             *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*      (1) For Insert A Vertex In Graph             *\n");
printf("\t\t*      (2) For Insert An Edge In Graph              *\n");
printf("\t\t*      (3) For Delete A Vetex In Graph              *\n");
printf("\t\t*      (4) For Delete An Edge In Graph              *\n");
printf("\t\t*      (5) Display Graph                            *\n");
printf("\t\t*      (6) for exit.....                            *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t*                                                   *\n");
printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        gotoxy(40,16);
        scanf("%d",&choice);
        system("cls");
         switch(choice)
        {
            case 1: cout<<"Enter a Vertex to be Inserted : ";
                    cin>>data;
                    insertVertex(data);
                    break;
            case 2: cout<<"Enter Edge to insert (origin and destination) : ";
					cin>>origin>>destination;
            		insertEdge(origin,destination);
            		break;
            case 3: cout<<"Enter a Vertex to Delete : ";
                    cin>>data;
                    if(findVertex(data)!=NULL)
                    {
                      deleteIncomingEdges(data);
                      deleteVertex(data);	
					}
					else cout<<"Vertex Not Found!\n";
                    break;
            case 4: cout<<"Enter Edge to delete (origin and destination) : ";
					cin>>origin>>destination;
            		deleteEdge(origin,destination);
            		break;
            case 5: display();
			        system("pause");
            	    system("cls");
            	    break;
            case 6: printf("thank you......\n\n\n\n\n\n\n");
					       exit(0);
            default : printf("please enter correct choice:\n");
            		         system("pause");
            		         system("cls");
        }
	}
	
}
