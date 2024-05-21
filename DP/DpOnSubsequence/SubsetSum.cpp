#include<bits/stdc++.h>
using namespace std;
    //Recursion
    bool slove(vector<int>arr , int sum ,int i ,int n){
        if(sum == 0)
          return true;
        if(i == n)
          return false;
        int take = slove(arr,sum-arr[i],i+1,n);
        int non_take = slove(arr , sum ,i+1,n);
        return take|non_take;
     
    }
    
    // Bottom-Up
    bool slove(vector<int> arr , int sum ){
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i =0;i<=n;i++)
          dp[i][0] = true;
        for(int i =n-1;i>=0;i--){
            for(int j = sum;j>=0;j-- ){
              if(j>=arr[i]) dp[i][j]= dp[i+1][j-arr[i]] | dp[i+1][j];
              else
                dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][sum];
    }
    
     //Space-Optimization
    bool slove(vector<int> arr , int sum ){
        int n = arr.size();
        vector<bool>front(sum+1,false) , cur(sum+1,false);
          front[0] = true;
        for(int i =n-1;i>=0;i--){
            for(int j = sum;j>=0;j-- ){
               if(j>=arr[i]) cur[j]= front[j-arr[i]] | front[j];
               else
                cur[j] = front[j];
            }
            front  = cur;
        }
        return front[sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        return slove(arr,sum);
        // code here 
    }
    int main() {
        // Test the isSubsetSum function
        vector<int> arr = {3, 34, 4, 12, 5, 2};
        int sum = 9;
        if (isSubsetSum(arr, sum))
            cout << "Subset with the given sum exists";
        else
            cout << "Subset with the given sum does not exist";
        
        return 0;
    }

    // Memoization
    vector<vector<int>> memo;

    bool slove(vector<int> arr, int sum, int i, int n) {
        if (sum == 0)
            return true;
        if (i == n)
            return false;
        if (memo[i][sum] != -1)
            return memo[i][sum];
        
        bool take = slove(arr, sum - arr[i], i + 1, n);
        bool non_take = slove(arr, sum, i + 1, n);
        
        return memo[i][sum] = take | non_take;
    }

