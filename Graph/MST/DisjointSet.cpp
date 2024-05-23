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
   
int main(){
    Disjoint_Set ds(5);
    ds.Union(0, 2);
    ds.Union(4, 2);
    ds.Union(3, 1);
    if (ds.find(4) == ds.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (ds.find(1) == ds.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (ds.find(3) == ds.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    Disjoint_SetbySize ds1(5);
    ds1.Union(0, 2);
    ds1.Union(4, 2);
    ds1.Union(3, 1);
    if (ds1.find(4) == ds1.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (ds1.find(1) == ds1.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (ds1.find(3) == ds1.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}