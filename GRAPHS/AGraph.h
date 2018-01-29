#include<iostream>
#include "CircleQueue.h"
using namespace std;
class graph
{
	int n,e;
	int **am;
	int *visited;
	public:
		graph(int v,int edge)
		{
			n=v;
			e=edge;
			am=new int*[n];
			for(int k=0;k<n;k++)
			{
				am[k]=new int[n];
			}
			visited=new int[n];
			for(int i=0;i<n;i++)
			for(int k=0;k<n;k++)
			am[i][k]=0;
		}
		void fillvisited();
		void display();
		void putdata();
		void DFS(int);
		void BFS(int);
};
void graph::fillvisited()
{
	for(int i=0;i<n;i++)
	visited[i]=0;
}
void graph::putdata()
{
	int i,j;
	for(int k=0;k<e;k++)
	{
		cout<<"\nenter the "<<k+1<<" edge : ";
		cin>>i>>j;
		am[i][j]=1; 
	}
}
void graph::display()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		cout<<am[i][j]<<" ";
	}
}
void graph::DFS(int i)
{
	if(!visited[i])
	{
		cout<<i<<" ";
		visited[i]=1;
		for(int j=0;j<n;j++)
		{
			if(am[i][j]==1&&visited[j]==0)
			DFS(j);
		}
	}
}
void graph::BFS(int i)
{
	cQueue<int> q(20);
	visited[i]=1;
	cout<<i<<" ";
	q.insert(i);
	while(!q.isEmpty())
	{
		i=q.Delete();
		for(int j=0;j<n;j++)
		{
			if(am[i][j]==1&&visited[j]==0)
			{
				q.insert(j);
				visited[j]=1;
				cout<<j<<" ";
			}
		}
	}
	
}
