#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++)
            cost[i][i]=0;
        for(auto it:edges){
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] =it[2];
        }
        for(int via =0;via<n;via++){
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j] = min(cost[i][j], cost[i][via]+cost[via][j]);
                }
            }
        }
     
        int city =INT_MAX;
        int ans =0;
        for(int i =0;i<n;i++){
            int temp =0;
            for(int j =0;j<n;j++ ){
                cout<<cost[i][j]<<" ";
                if(cost[i][j] <=distanceThreshold){
                    temp++;
                }
            }
            cout<<endl;
            if(city>=temp){
             city =temp;
             ans = i;
            }
        }
        return ans;
    }
};