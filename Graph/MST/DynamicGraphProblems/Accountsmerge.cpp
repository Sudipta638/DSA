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
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
               int n = details.size();
        Disjoint_Set ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.UnionbySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUparent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};