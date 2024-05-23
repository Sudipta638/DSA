

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[] ,int stnode ,vector<int>vis)
    {
          queue<pair<int,int>> q;
          q.push({stnode,-1});
          vis[stnode] = 1;
          while (!q.empty())
          {
              auto it = q.front();
              int parent = it.second;
              int node = it.first;
              q.pop();
              // vis[node]=1;
             // bfs.push_back(node);
              for (auto adjnode : adj[node])
              {
                  if (vis[adjnode] == 0)
                  {
                      vis[adjnode] = 1;
                      q.push({adjnode,node});
                  }
                  else if(adjnode != parent)
                    return true;
              }
          }
          return false;
    // Code here
    }

    bool dfs(vector<int>adj[] ,int parent ,int node ,vector<int> &vis){
        vis[node]=1;
        for(auto adjnode :adj[node]){
            if(vis[adjnode] == 0){
                if(dfs(adj,node,adjnode,vis))
                  return true;
            }
            else if(adjnode!= parent){
                 return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        // for(int i =0;i<V;i++){
        //     if(!vis[i]&&bfs(adj,i,vis))
        //       return true;
        // }
          for(int i =0;i<V;i++){
            if(!vis[i]){
                vis[i] = 1;
                if(dfs(adj,-1,i,vis)){
                      return true;
                   }
               }
            }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends