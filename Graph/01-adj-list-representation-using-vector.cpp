#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    vector<vector<int>> adjList;
    int size;

    public:

    Graph(int size): size(size) {
        this->adjList = vector<vector<int>>(size, vector<int>());
    }

    void addEdge(int v, int u) {
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    void printGraph() {
        for (int i = 0; i < size; i++) {
            cout << i << ":";

            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << "->";
            }
            cout << "null" << endl;
        }
    }
};

int main(){

    int size = 7; // number of nodes.
    Graph graph(size);
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {4, 5}, {4, 6}, {5, 6}};

    for (int i = 0; i < edges.size(); i++)
    {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    graph.printGraph();
    return 0;
}