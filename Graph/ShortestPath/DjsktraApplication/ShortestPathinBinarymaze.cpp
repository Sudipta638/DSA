// 1091. Shortest Path in Binary Matrix
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:

// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0] == 1)
        return -1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dist(row, vector<int>(col, 1e9));
    dist[0][0] = 1;
    pq.push({1, {0, 0}});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int distance = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if (r == row - 1 && c == col - 1)
            return distance;
        for (int dr = -1; dr <= 1; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] == 1 || dist[nr][nc] <= distance + 1)
                    continue;
                dist[nr][nc] = distance + 1;
                pq.push({distance + 1, {nr, nc}});
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << shortestPathBinaryMatrix(grid);
    return 0;
}