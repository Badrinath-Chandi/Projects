#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <queue>

// Number of vertices in the graph
#define V 5
using namespace std;

void dfsutil(int graph[V][V],bool* visited,int u)
{
	visited[u] = true;
	cout << "visiting " << u << endl;
	for (int i = 0; i < V; i++) {
		if (!visited[i] && graph[u][i])
			dfsutil(graph, visited, i);
	}
}
void dfs(int graph[V][V])
{
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++) {
		if (visited[i] == false)
			dfsutil(graph,visited, i);
	}
}

void bfs(int graph[V][V])
{
	queue<int> mQ;
	int u = 0;
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	mQ.push(u);
	visited[u] = true;
	while(!mQ.empty()) {
		int tmp = mQ.front();		 
		cout << "visited " << tmp << endl;
		mQ.pop();
		for (int j = 0; j < V; j++) {
			if (graph[tmp][j] && !visited[j]) {
				visited[j] = true;
				mQ.push(j);
			}
		}
	}
}
int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
	};
	dfs(graph);
	cout << "Now doing bfs " << endl;
	bfs(graph);
	getchar();
}