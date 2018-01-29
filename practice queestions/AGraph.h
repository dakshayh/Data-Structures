#include<iostream>
#include "CircleQueue.h"
using namespace std;
class graph
{
	int **g;
	int e,n;
	int *visited;
	public:
			void fill();
		graph(int ve,int ed)
		{
			e=ed;n=ve;
			int i;
			g=new int*[n];
			for(i=0;i<n;i++)
			g[i]=new int[n];
			visited = new int[n];
			for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			g[i][j]=0;
		}
		void display()
		{
			int i,j;
			for(i=0;i<n;i++)
			{
				cout<<endl;
				for(j=0;j<n;j++)
				cout<<g[i][j]<<"  ";
			}
		}
		void insert()
		{
			for(int i=0;i<e;i++)
			{int p,j;
			cout<<"\nenter the "<<i+1<<" edge : ";
			cin>>p>>j;
			g[p][j]=1;
			}
		}
		void DFS(int i)
		{
			if(!visited[i])
			{
				cout<<i<<"  ";
				visited[i]=1;
				for(int j=0;j<n;j++)
				{
					if(g[i][j]==1&&visited[j]==0)
					{
						DFS(j);
					}
				}
			}
		}
		void BFS(int i)
		{
			cQueue<int> q(20);
			visited[i]=1;
			cout<<i<<"  ";
			q.insert(i);
			while(!q.isEmpty())
			{
				i=q.Delete();
				for(int j=0;j<n;j++)
				{
					if(g[i][j]==1&&visited[j]==0)
					{
						q.insert(j);
						cout<<j<<"  ";
					}
				}
			}
		}
		
};
void graph::fill()
{
	for(int i=0;i<n;i++)
	visited[i]=0;	
}
