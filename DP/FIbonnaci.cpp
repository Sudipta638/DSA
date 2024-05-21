#include<bits/stdc++.h>
using namespace std;
int recfibonnaci(int n){
    if(n<=1){
        return n;
    }
    return recfibonnaci(n-1)+recfibonnaci(n-2);
}
int memofibonnaci(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=memofibonnaci(n-1,dp)+memofibonnaci(n-2,dp);
    return dp[n];
}

int tabfibonnaci(int n){
    vector<int>dp(n+1,-1);
    dp[0] =0;
    dp[1] =1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int spaceoptimisedfibonnaci(int n){
     int prev2 =0;
     int prev =1;
     for(int i =2;i<=n;i++){
        int cur = prev2+prev;
        prev2 = prev;
        prev = cur;
     }
     return prev;
}
int main(){
    int n;
    cout<<"Enter the number of terms you want to print: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<recfibonnaci(i)<<" ";
    }
    cout<<endl;
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        cout<<memofibonnaci(i,dp)<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<tabfibonnaci(i)<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<spaceoptimisedfibonnaci(i)<<" ";
    }
    return 0;
}