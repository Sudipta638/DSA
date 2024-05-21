// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200

#include<bits/stdc++.h>
using namespace std;
 int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int>front(c+1,INT_MAX),cur(c+1,INT_MAX);
        for(int i =r-1;i>=0;i--){
            for(int j = c-1;j>=0;j--){
                if(i == r-1&& j == c-1)
                  cur[j] = grid[i][j];
               else  if(j == c)
                  cur[j]= INT_MAX;
                else
                cur[j]= grid[i][j]+min(front[j],cur[j+1]);
            }
             front = cur;
        }
        return front[0];
    }

     int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        vector<int>front(r+1,INT_MAX),cur(r+1,INT_MAX);
        for(int i =r-1;i>=0;i--){
            for(int j = r-1;j>=0;j--){
                if(i == r-1)
                  cur[j] = triangle[i][j];
               else  if(j > i)
                  cur[j]= INT_MAX;
                else
                cur[j]= triangle[i][j]+min(front[j],front[j+1]);
            }
             front = cur;
        }
        return front[0];
    }
