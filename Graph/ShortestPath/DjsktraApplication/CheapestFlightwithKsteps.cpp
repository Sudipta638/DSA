// 787. Cheapest Flights Within K Stops
// Solved
// Medium
// Topics
// Companies
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
// Example 2:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
// Example 3:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

// Constraints:

// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst


#include <bits/stdc++.h>
using namespace std;
 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
         queue<pair<int,pair<int, int>>> pq;
         vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it= pq.front();
            pq.pop();
            int distance = it.first;
            int node = it.second.first;
            int steps = it.second.second;
            // if(node ==dst)
            //   return distance;
            if(steps == k+1)
              continue;
            for(auto it:adj[node]){
                if(dist[it.first]>distance+it.second && steps<=k){
                    dist[it.first] = distance+it.second;
                    pq.push({dist[it.first],{it.first,steps+1}});
                }
            }

        }
        return dist[dst]==1e9?-1:dist[dst];
    }
int main()
{
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}