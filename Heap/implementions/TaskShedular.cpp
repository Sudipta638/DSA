#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if(n==0)
          return len;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int> mp;
        for(auto it:tasks){
          mp[it]++;
        }
        for(auto it:mp)
         pq.push({it.second,it.first});
        int x =0;
        int y =0;
        while(!pq.empty()){
            y =n;
            queue<pair<int,char>> q;
            while(y>=0 &&!pq.empty()){
                auto it = pq.top();
                 pq.pop();
                 if(it.first>1)
                    q.push({it.first-1,it.second});
                x++;
                y--;
            }
            cout<<q.size()<<endl;
            cout<<y<<endl;
            x+=y+1;
            while(!q.empty()){
                auto it = q.front();
                pq.push({it.first,it.second});
                q.pop();
            }    
            
        }
        return x-y-1;
    }
};