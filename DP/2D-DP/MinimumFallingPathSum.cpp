// 31. Minimum Falling Path Sum
// Solved
// Medium
// Topics
// Companies
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


#include<bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>front(c+2,INT_MAX),cur(c+2,INT_MAX);
        for(int j = c;j>0;j--)
          front[j] = matrix[r-1][j-1];
        for(int i =r-2;i>=0;i--){
            for(int j = c;j>0;j--){
                cur[j]= matrix[i][j-1]+min(min(front[j],front[j+1]),front[j-1]);;
            }
             front = cur;
        }
        return *min_element(front.begin(),front.end());
    }
