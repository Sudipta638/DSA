#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>parimst (int V,vector<vector<int>>&graph ,int&sum){
    vector<vector<pair<int, int>>> adj(V);
    for(auto edge : graph){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
     vector<pair<int,int>>ans;
     pq.push({0,{0,-1}});
     vector<bool>vis(V,false);
     while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dist = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        vis[node] = true;
        sum+=dist;
        ans.push_back({parent,node});
        for(auto it:adj[node]){
            if(!vis[it.first]){
                pq.push({it.second,{it.first,node}});
            }
        }
     }
     return ans;
}

int main(){
    int V = 5; // number of vertices
    vector<vector<int>> graph = {
        {0, 1, 2}, // edge from vertex 0 to vertex 1 with weight 2
        {0, 3, 6}, // edge from vertex 0 to vertex 3 with weight 6
        {1, 2, 3}, // edge from vertex 1 to vertex 2 with weight 3
        {1, 3, 8}, // edge from vertex 1 to vertex 3 with weight 8
        {1, 4, 5}, // edge from vertex 1 to vertex 4 with weight 5
        {2, 4, 7}, // edge from vertex 2 to vertex 4 with weight 7
        {3, 4, 9}  // edge from vertex 3 to vertex 4 with weight 9
    };
    
    int sum = 0; // to store the sum of weights in MST
    vector<pair<int, int>> mst = parimst(V, graph, sum); // calculate MST using Prim's algorithm
    // Print the MST
// Print the MST as a tree-like structure
cout << "Minimum Spanning Tree (MST):" << endl;
for(auto edge : mst){
    cout << edge.first << " -- " << edge.second << endl;
}

// Print the graph with proper node weight and direction
cout << "Graph:" << endl;
for(auto edge : graph){
    cout << edge[0] << " --(" << edge[2] << ")-- " << edge[1] << endl;
}
   
    
    // Print the minimum weight of MST
    cout << "Minimum weight of MST: " << sum << endl;
    
    return 0;
}