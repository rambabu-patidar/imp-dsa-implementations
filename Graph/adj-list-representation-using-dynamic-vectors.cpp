#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<int>* adjList;
    int size;

public:
    Graph(int size) : size(size)
    {
        this->adjList = new vector<int>[size];
    }

    ~Graph() {
        delete adjList;
    }
    
    void addEdge(int v, int u)
    {
        adjList[v].push_back(u);
        adjList[u].push_back(v);
        return;
    }

    void dfs(int src, vector<int> &visited) {

        cout << src << " ";
        visited[src] = 1;

        for (int nbr: adjList[src]) {
            if (!visited[nbr]){
                dfs(nbr, visited);
            }
        }
        
    }
};

int main()
{

    int size = 7; // number of nodes.
    Graph graph(size);
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {4, 5}, {4, 6}, {5, 6}};

    for (int i = 0; i < edges.size(); i++)
    {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    vector<int> visited(size, 0);
    graph.dfs(0, visited);
    return 0;
}