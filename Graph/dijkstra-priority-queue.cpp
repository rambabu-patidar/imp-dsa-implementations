#include<bits/stdc++.h>
using namespace std;

// returns the distance of all vertex from the src vertex
// those are not reachable their distance is infinity.

// Dijkstra's Algorithm


vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(adj.size(), INT_MAX);

    q.push(make_pair(0, src));
    dist[src] = 0;
    while (!q.empty()) {
        pair<int, int> currPair = q.top();
        int currDist = currPair.first;
        int currNode = currPair.second;
        q.pop();

        for (pair<int, int> nbrPair : adj[currNode]) {
            int nbrWt = nbrPair.first;
            int nbrIdx = nbrPair.second;

            if (currDist + nbrWt < dist[nbrIdx]) {
                dist[nbrIdx] = currDist + nbrWt;
                q.push({dist[nbrIdx], nbrIdx});
            }
        }
    }
    return dist;
}
