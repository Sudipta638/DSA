#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &graph, int start, vector<int> &vis)
{
    int V = graph.size();

    queue<int> q;
    q.push(start);
    vis[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : graph[node])
        {
            if (vis[it] == -1)
            {
                vis[it] = !vis[node];
                q.push(it);
            }
            else if (vis[it] == vis[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (!bfs(graph, i, vis))
                return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << isBipartite(graph);
    return 0;
}