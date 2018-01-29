// implementation of graph using array
#include"CircleQueue.h"
#include<iostream>
using namespace std;
class Graph
{
	int n,e;
	int **g;
	int *visited;
	public:
	Graph(int v,int edges)
	{
		n=v;   e=edges;
		g=new int*[n];
		for(int i=0;i<n;i++)
		g[i]=new int[n];
		visited=new int[n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				g[i][j]=0;
		}
		}
	void fillvisited()
	{
		for(int i=0;i<n;i++)
			visited[i]=0;
	}
		void read()
		{
			int i,j;
			cout<<"\nEnter the edges (STARTING VERTEX 0):\n ";
			for(int x=0;x<e;x++)
			{
				cout<<"\nEnter the edge(%d): "<<x+1;
				cin>>i>>j;
				g[i][j]=1;
				// if it is undirected graph then also store edge in g[j][i]
				//g[j][i]=1;
			}

			}
		void display()
		{
			cout<<"\nThe adjecendy matrix of  graph is:\n\n ";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
	   				cout<<g[i][j]<<"\t";
				cout<<"\n";
			}

		}
		void BFS(int v)
		{
			int i;
			fillvisited();
			cQueue<int> q;
			q.insert(v);
			cout<<"\n visit list\n"<<v;
			visited[v]=1;
			while(!q.isEmpty())
			{
				v=q.Delete();
				// visit and add adjacency vertices
				for(i=0;i<n;i++)
				{
					if(visited[i]==0 && g[v][i]!=0)
					{
						q.insert(i);
						visited[i]=1;
						cout<<i<<"\t";
					}
				}
			}
		}
	
		void DFS(int i)
		{
			if(!visited[i])
			{
				cout<<i<<"\t";
				visited[i]=1;
				for(int j=0;j<n;j++)
				{
					if(g[i][j]==1&&visited[j]==0)
			 			DFS(j);
				}
			}
		}


					
};








