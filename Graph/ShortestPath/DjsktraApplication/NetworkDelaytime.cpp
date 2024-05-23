// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)#pragma endregio
#include<bits/stdc++.h>
using namespace std;
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>>adj[n];
       for(auto it:times){
        adj[it[0]-1].push_back({it[1]-1,it[2]});
       }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       vector<int>dist(n,1e9);
       dist[k-1] =0;
       pq.push({0,k-1});
       while(!pq.empty()){
            auto it= pq.top();
            int node = it.second;
            int dis =it.first;
            pq.pop();
            for(auto it:adj[node])
            {
                int v =it.first;
                int w = it.second;
                if(dis+w<dist[v]){
                    dist[v] =dis+w;
                    pq.push({dis+w,v});
                }
            }
        }
        int maxi =0;
        for(int i =0 ;i<n;i++){
            if(dist[i]== 1e9)
               return -1;
           maxi = max(maxi , dist[i]);
        }
        return maxi;
    }
    int main(){
        vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
        int n = 4;
        int k = 2;
        cout<<networkDelayTime(times,n,k)<<endl;
        return 0;
    }
