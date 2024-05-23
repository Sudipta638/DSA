#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto v : adj[i])
            indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it;
        topo.push_back(node);
        for (auto adjnode : adj[node])
        {
            indegree[adjnode]--;
            if (indegree[adjnode] == 0)
                q.push(adjnode);
        }
    }
    while (!q.empty())
    {
        topo.push_back(q.front());
        q.pop();
    }
    return topo.size() != V;
    // code here
}

int main()
{
    int V = 5; // number of vertices
    vector<int> adj[V]; // adjacency list

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);

    if (isCyclic(V, adj))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}