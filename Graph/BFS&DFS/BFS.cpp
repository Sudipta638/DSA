#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    vector<int> vis(V, 0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // vis[node]=1;
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
    // Code here
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[0].push_back(2);
    vector<int> res = bfsOfGraph(V, adj);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}