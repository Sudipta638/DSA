// 542. 01 Matrix
// Solved
// Medium
// Topics
// Companies
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, +1, -1};
    vector<vector<int>> upm(row, vector<int>(col, -1));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                upm[i][j] = 0;
                q.push({{i, j}, 0});
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int r = it.first.first;
        int c = it.first.second;
        int dist = it.second;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= row || nc >= col || mat[nr][nc] == 0 || upm[nr][nc] != -1)
                continue;
            upm[nr][nc] = dist + 1;
            ans = max(ans, dist + 1);
            q.push({{nr, nc}, dist + 1});
        }
    }
    return upm;
}

int main()
{
    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> res = updateMatrix(v);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}