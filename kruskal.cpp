#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge
{
    public:
        int v1;
        int v2;
        int weight;        
};

bool comp(Edge a, Edge b)
{
    return (a.weight < b.weight);
}

int find_parent(int v, int *parent)
{
    if(parent[v] == v) return v;
    
    return find_parent(parent[v], parent);
}

void mst_kruskal(Edge * input, int V, int E)
{
    sort(input, input + E, comp);
    Edge * output = new Edge[V - 1];
    int * parent = new int[V];
    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    
    while(count != V - 1)
    {
        Edge current_edge = input[i];
        int source_p = find_parent(current_edge.v1, parent);
        int des_p = find_parent(current_edge.v2, parent);
        
        if(source_p != des_p)
        {
            output[count] = current_edge;
            count++;
            parent[source_p] = des_p;
        }
        i++;
    }
    
    for(int i = 0; i < V - 1; i++)
    {
        if(output[i].v1 < output[i].v2)
            cout << output[i].v1 << " " << output[i].v2 << " " << output[i].weight << endl;
        else
            cout << output[i].v2 << " " << output[i].v1 << " " << output[i].weight << endl;
    
    }
    
    
}


int main()
{
    int V, E;
    cin >> V >> E;    
    Edge* input = new Edge[E];
    for(int i = 0; i < E; i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        input[i].v1 = s;
        input[i].v2 = d;
        input[i].weight = w;
    }
    mst_kruskal(input, V, E);
    

  return 0;
}

