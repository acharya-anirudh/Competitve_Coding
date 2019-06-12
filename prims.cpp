#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int * weights, bool *visited, int n)
{
	int minVertex = -1; // Let minVertex index is -1 initially
	for(int i = 0; i < n; i++)
	{
		//if not visited then
		//	if its -1 then update the minVertex to i 
		//	else if its not -1 then check if weight of node < weight of minVertex 
			
		if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
		{
			minVertex = i;
		}
	}

	return minVertex;
}

void prims(int **edges, int n)
{
	int * parent = new int[n];
	int * weight = new int[n];
	bool * vis = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	parent[0] = -1; //source is node 0
	weight[0] = 0;

	//out of all available vertices, pick the one with 
	//min weight
	
	for(int i = 0; i < n; i++)
	{
		//find min vertex from weights
		int minVertex = findMinVertex(weights, visted, n); 
		visited[minVertex] = true;
		//explore unvisited neighbours

		for(int j = 0; j < n; j++)
		{
			if(edges[minVertex][j] != 0 && !visited[j]) // if valid edge between min vertex and its neighbours
			{
				if(edges[minVertex][j] < weights[j]) // if weight is less then consider it
				{
					weights[j] = edges[minVertex][j]; // update weight of vertex with edge weight
					parent[j] = minVertex; //update parent of the node as minVertex
				}
			}
		}
	}

	//print smaller vertex first
	for(int i = 1; i < v; i++)
	{
		if(parent[i] < i)
		{
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}

		else
			cout << i << " " << parent[i] << " " << weights[i] << endl;
	}
}

int main()
{
	int n;
	int e;
	cin >> n >> e;
	int ** edges = new int*[n];
	
	for(int i = 0 ; i < n; i++)
	{
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	//initialise adjacency matrix
	for(int i = 0; i < e; i++)
	{
		int f,s,w;
		cin >> f >> s >> w;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	prims(edges,n);

	for(int i = 0; i < n; i++)
	{
		delete [] edges[i];
	}

	delete [] edges;

}


