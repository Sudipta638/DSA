// here are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example 1:


// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:


// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
 

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.

#include<bits/stdc++.h>
using namespace std;

class Disjoint_Set{
	    vector<int> size, parent;
	    public:
	    Disjoint_Set(int n){
	        size.resize(n+1,1);
	        parent.resize(n+1);
	        for(int i =0;i<=n;i++){
	            parent[i]=i;
	        }
	    }
	    int findUparent(int node){
	        if(node == parent[node])
	          return node;
	        return parent[node]= findUparent(parent[node]);
	    }
	    void UnionbySize(int u ,int v){
	        int ulp_u = findUparent(u);
	        int ulp_v = findUparent(v);
	        if(ulp_u==ulp_v)
	         return ;
	        if(size[ulp_u]<size[ulp_v]){
	            parent[ulp_u]= ulp_v;
	            size[ulp_v]+= size[ulp_u];
	        }else{
	            parent[ulp_v]= ulp_u;
	            size[ulp_u]+= size[ulp_v]; 
	        }
	    }
	};
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size<n-1)
          return -1;
        Disjoint_Set ds(n);
        for(auto it:connections){
            ds.UnionbySize(it[0],it[1]);
        }
        int ans =0;
        for(int i =0;i<n;i++){
            if(i!=ds.findUparent(i)){
                ans++;
            }
        }
        return n-ans-1;
    }

    int main(){
        int n = 6;
        vector<vector<int>> connections = {
            {0, 1},
            {0, 2},
            {0, 3},
            {1, 2},
            {1, 3}
        };
        cout<<makeConnected(n,connections)<<endl;
        return 0;
    }
