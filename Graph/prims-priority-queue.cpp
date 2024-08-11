#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> myPair;

// Prims Algorithm
// It is a greedy algorithm, Used to find the MST
// To know what is MST Go on my gitsts or somewhere on internet
// whole implementation is in cppStuff Repo

// If this is really sucking you then see another efficient way below the current file.

vector<myPair> primsAlgo(vector<vector<pair<int, int>>> &adjList, int n)
{
    priority_queue<myPair, vector<myPair>, greater<myPair>> pq;

    vector<myPair> MSTPairs;

    vector<int> visited(n, 0);

    pq.push({0, {0, 0}});

    while (!pq.empty() && MSTPairs.size() <= n - 1)
    {
        myPair minWtEdge = pq.top();
        int wt = minWtEdge.first;
        int u = minWtEdge.second.first;
        int v = minWtEdge.second.second;
        pq.pop();

        if (visited[v])
            continue;

        if (u != v)
        { // to handle the case where we don't push the first imagnary src
            MSTPairs.push_back({wt, {u, v}});
        }

        visited[v] = 1;

        for (pair<int, int> nbrPair : adjList[v])
        {
            int nbrNode = nbrPair.first;
            int wt = nbrPair.second;
            if (!visited[nbrNode])
            {
                pq.push({wt, {v, nbrNode}});
            }
        }
    }

    return MSTPairs;
}