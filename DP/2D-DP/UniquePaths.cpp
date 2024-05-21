// 62. Unique Paths
// Solved
// Medium
// Topics
// Companies
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:

// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Constraints:

// 1 <= m, n <= 100

#include <bits/stdc++.h>
using namespace std;
// int slove(int i ,int j , int m ,int n){
//      if(i == m-1 && j == n -1)
//        return 1;
//      if(i == m || j == n)
//        return 0;
//     return slove(i+1 ,j,m,n)+slove(i,j+1,m,n);
// }
int slove(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}

// int slove( int m ,int n){
//     vector<int>front(n+1,0) , cur(n+1,0);
//     front[n-1]=1;
//     for(int i = m-1 ;i>=0;i--){
//         for(int j = n-1;j>=0;j--  ){
//             cur[j]= front[j]+cur[j+1];
//         }
//         front = cur;
//     }
//     return front[0];
// }

int uniquePaths(int m, int n)
{
    return slove(m, n);
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<long long int> front(n + 1, 0), cur(n + 1, 0);
    front[n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (obstacleGrid[i][j] == 0)
                cur[j] = front[j] + cur[j + 1];
            else
                cur[j] = 0;
            // cout<<obstacleGrid[i][j]<<endl;
        }
        front = cur;
    }
    return front[0];
}