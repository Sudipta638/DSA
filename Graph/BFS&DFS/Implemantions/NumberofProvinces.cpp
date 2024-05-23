// 547. Number of Provinces
// Solved
// Medium
// Topics
// Companies
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> adj, int V, vector<int> &vis, int node)
{
    queue<int> q;
    q.push(node);
    // bfs.push_back(node);
    vis[node] = node;
    while (!q.empty())
    {
        int node2 = q.front();
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (adj[node2][i] == 1)
            {
                if (vis[i] == -1)
                {
                    vis[i] = node;
                    q.push(i);
                }
            }
        }
    }
    return;
}

void dfs(int V, vector<vector<int>> adj, vector<int> &vis, int stnode,
         int node)
{
    vis[node] = stnode;
    //  dfs.push_back(node);
    for (int i = 0; i < V; i++)
    {
        if (adj[node][i] == 1)
        {
            if (vis[i] == -1)
            {
                // vis[i] = stnode;
                dfs(V, adj, vis, stnode, i);
            }
        }
    }

    return;
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected.size();
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            bfs(isConnected, V, vis, i);
        }
        // }
        //  for(int i =0;i<V;i++){
        //     if(vis[i]== -1){
        //         dfs(V,isConnected,vis,i,i);
        //     }
        // }
        int ans = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == i)
                ans++;
        }
        return ans;
    }
}
int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected);
    return 0;
}