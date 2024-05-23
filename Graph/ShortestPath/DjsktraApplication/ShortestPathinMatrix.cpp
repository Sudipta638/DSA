// 1631. Path With Minimum Effort
// Solved
// Medium
// Topics
// Companies
// Hint
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
 

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

#include <bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>> &heights)
{
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<int>> effort(row, vector<int>(col, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    effort[0][0] = 0;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int e = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if (r == row - 1 && c == col - 1)
            return e;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < row && nc < col)
            {
                int ne = max(e, abs(heights[r][c] - heights[nr][nc]));
                if (ne < effort[nr][nc])
                {
                    effort[nr][nc] = ne;
                    pq.push({ne, {nr, nc}});
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(heights) << endl;
    return 0;
}