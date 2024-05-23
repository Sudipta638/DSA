#include<bits/stdc++.h>
using namespace std;

class Solution {
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int ,int > mp;
        int maxrow =0;
        int maxcol =0;
        for(auto it : stones){
            maxrow = max(it[0],maxrow);
            maxcol = max(it[1],maxcol);

        }
        Disjoint_Set ds(maxrow+maxcol+1);
         for(auto it : stones){
            int row = it[0];
            int col = it[1]+maxrow+1;
            ds.UnionbySize(row,col);
            mp[row]=1;
            mp[col]=1;

        }
        int cnt =0;
        for(auto it:mp){
            if(ds.findUparent(it.first)== it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};