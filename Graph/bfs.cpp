#include <bits/stdc++.h>
using namespace std;

// when you don't wanna to distinguish the levels
void bfs(vector<vector<int>> &adjList, int src)
{
    vector<int> visited(adjList.size(), 0);

    queue<int> q;
    q.push(src);
    visited[src] = true; // in c++ true is 1

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for (int nbr : adjList[currNode])
        {
            if (!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
}

// when you want to distinguish the levels
void bfs(vector<vector<int>> &adjList, int src)
{
    vector<int> visited(adjList.size(), 0);

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int qSize = q.size();

        for (int i = 1; i <= qSize; i++)
        {
            int currNode = q.front();
            q.pop();

            for (int nbr : adjList[currNode])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
}