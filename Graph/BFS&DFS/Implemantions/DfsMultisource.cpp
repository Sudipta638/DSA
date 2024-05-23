//     Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we
// have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// Your Task:

// You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] == 0 or grid[i][j] == 1

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c, string &path, int dr[4], int dc[4], char dir[4], vector<vector<int>> &vis, int n, int m)
{
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        path += dir[i]; ///////////fdffff
        if (nr >= n || nc >= m || nr < 0 || nc < 0 || grid[nr][nc] == 0 || vis[nr][nc] == 1)
            continue;

        dfs(grid, nr, nc, path, dr, dc, dir, vis, n, m);
        // path.pop_back();
    }
    return;
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<string> st;
    int dr[4] = {0, 0, +1, -1};
    int dc[4] = {+1, -1, 0, 0};
    char dir[4] = {'u', 'd', 'r', 'l'};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                string path = "o";
                dfs(grid, i, j, path, dr, dc, dir, vis, n, m);
                // cout<<path<<endl;
                st.insert(path);
            }
        }
    }
    return st.size();
    // code here
}

int main()
{
    vector<vector<int>> v{{1, 1, 0, 0, 0},
                          {1, 1, 0, 0, 0},
                          {0, 0, 0, 1, 1},
                          {0, 0, 0, 1, 1}};
    cout << countDistinctIslands(v);
    return 0;
}