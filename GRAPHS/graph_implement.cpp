#include<iostream>
#include "AGraph.h"
using namespace std;
int main()
{
	int n,e,v;
	cout<<"\nenter number of vertices and edges : ";
	cin>>n>>e;
	graph gh(n,e);
	gh.putdata();
	cout<<"\nadjacency matrix is : ";
	gh.display();
	cout<<"\nenter the vertex for DFS : ";
	cin>>v;
	gh.fillvisited();
	gh.DFS(v);
	cout<<"\nenter the vertex for BFS : ";
	cin>>v;
	gh.fillvisited();
	gh.BFS(v);
	return 0;
}




