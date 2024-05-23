#include <bits/stdc++.h>
using namespace std;

void dfs(stack<int> &st, vector<bool> &vis, vector<int> adj[], int node)
{
    vis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (vis[adjnode] == 0)
            dfs(st, vis, adj, adjnode);
    }
    st.push(node);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            dfs(st, vis, adj, i);
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
    // code here
}
int main()
{
    int V = 6;          // number of vertices
    vector<int> adj[V]; // adjacency list

    // add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(5);

    vector<int> result = topoSort(V, adj);

    // print the vertices in topological order
    cout << "Topological Order: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}