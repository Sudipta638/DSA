#include<bits/stdc++.h>
using namespace std;
class Disjoint_Set{
    public:
    vector<int>parent;
    vector<int>rank;
    Disjoint_Set(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++){
            parent[i] =i;
            rank[i] =0;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x,int y){
        int x_rep = find(x);
        int y_rep = find(y);
        if(x_rep==y_rep)
            return;
        if(rank[x_rep]<rank[y_rep]){
            parent[x_rep] = y_rep;
        }
        else if(rank[x_rep]>rank[y_rep]){
            parent[y_rep] = x_rep;
        }
        else{
            parent[x_rep] = y_rep;
            rank[y_rep]++;
        }
    }
};

class Disjoint_SetbySize{
    public:
    vector<int>parent;
    vector<int>size;
    Disjoint_SetbySize(int n){
        parent.resize(n);
        size.resize(n);
        for(int i =0;i<n;i++){
            parent[i] =i;
            size[i] =1;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x,int y){
        int x_rep = find(x);
        int y_rep = find(y);
        if(x_rep==y_rep)
            return;
        if(size[x_rep]<size[y_rep]){
            parent[x_rep] = y_rep;
            size[y_rep]+=size[x_rep];
        }
        else{
            parent[y_rep] = x_rep;
            size[x_rep]+=size[y_rep];
        }
    }
};

int MST(int V,vector<vector<int>>&graph){
    vector<vector<int>>edges;
    for(int i =0;i<V;i++){
        for(int j =0;j<V;j++){
            if(graph[i][j]!=0){
                edges.push_back({i,j,graph[i][j]});
            }
        }
    }
    sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    });
    Disjoint_Set ds(V);
    int sum =0;
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        if(ds.find(u)!=ds.find(v)){
            ds.Union(u,v);
            sum+=weight;
        }
    }
    return sum;
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
    cout<<MST(V,graph);
    return 0;
}