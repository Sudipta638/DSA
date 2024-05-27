#include<bits/stdc++.h>
using namespace std;
class Solution {
    int timer =1;
    void dfs(int node ,int parent , vector<int>adj[],vector<int>&vis,int toi[],int low[],vector<vector<int>>&bridges){
        vis[node] =1;
       
        low[node]=timer;
        toi[node]= timer;
         timer++;
        for(auto adjnode:adj[node]){
            if(adjnode==parent) 
             continue;
            if(vis[adjnode]==0){
                dfs(adjnode,node,adj,vis,toi,low,bridges);
                low[node] = min(low[node],low[adjnode]);
                if(toi[node]<low[adjnode]){
                    bridges.push_back({adjnode,node});
                }
            }
            else{
                low[node] = min(low[node],low[adjnode]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        int toi[n];
        int low[n];
        dfs(0,-1,adj,vis,toi,low,bridges);
        // for(auto it:bridges){
        //     ans.push_back(it);
        // }
        return bridges;
    }
};