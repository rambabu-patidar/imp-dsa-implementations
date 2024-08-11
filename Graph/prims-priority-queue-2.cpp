#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge; // (weight, vertex)

void primsAlgorithm(int V, vector<vector<Edge>> &adjList)
{
    // Priority queue to select the edge with the smallest weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> key(V, INT_MAX);  // Store the minimum weight edge for each vertex
    vector<int> parent(V, -1);    // Store the parent of each vertex
    vector<bool> inMST(V, false); // To keep track of vertices included in MST

    int startVertex = 0; // Start with vertex 0
    pq.push({0, startVertex});
    key[startVertex] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second; // Get vertex with the smallest key value
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto &[weight, v] : adjList[u])
        {
            // If v is not in MST and the weight of u-v is smaller than the current key value of v
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Output the edges of the MST
    cout << "Edges in the MST:\n";
    for (int v = 1; v < V; ++v)
    {
        cout << parent[v] << " - " << v << " (Weight: " << key[v] << ")\n";
    }
}

/*
after getting the intuision I wrote the previous code that is really hard to understand
but yeah that works fine.

This code I got directly from somewhere.*/