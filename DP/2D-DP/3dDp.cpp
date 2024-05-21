// Chocolates Pickup
// HardAccuracy: 58.1%Submissions: 8K+Points: 8
// Find better job opportunities this summer via Job-A-Thon Hiring Challenge!

// banner
// You are given an r rows and c cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

// You have two robots that can collect chocolates for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of chocolates collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the chocolates.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.
// Example:

// Input:
// r = 3, c = 4
// grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output:
// 24
// Explanation:
// Path of robot #1 and #2 are described in color green and blue respectively. Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12. Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of cherries: 12 + 12 = 24.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function Solve() which takes r rows, c columns, and a matrix grid and returns the maximum number of chocolates that can be collected by two robots.

// Expected Time Complexity: O(r * c * c)
// Expected Space Complexity: O(c * c * c)

// Constraint:
// 2 <= r < = 70
// 0 <= grid[i][j] <= 100

#include <bits/stdc++.h>
using namespace std;

// Recursion
int f(int n, int m, vector<vector<int>> &grid, int i, int j1, int j2)
{
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    int maxi = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int jn1 = j1 + dj1;
            int jn2 = j2 + dj2;
            if (jn1 < 0 || jn2 < 0 || jn1 >= m || jn2 >= m)
                continue;
            if (j1 == j2)
                maxi = max(maxi, grid[i][j1] + f(n, m, grid, i + 1, jn1, jn2));
            else
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(n, m, grid, i + 1, jn1, jn2));
        }
    }
    return maxi;
}

// Bottom-up
int f(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(m + 1, 1e9)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j1] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int jn1 = j1 + dj1;
                        int jn2 = j2 + dj2;
                        if (jn1 < 0 || jn2 < 0 || jn1 >= m || jn2 >= m)
                            continue;
                        if (j1 == j2)
                            maxi = max(maxi, grid[i][j1] + dp[i + 1][jn1][jn2]);
                        else
                            maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][jn1][jn2]);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

// Space-optimazaation

int sp(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m + 1, vector<int>(m + 1, 1e9)), cur(m + 1, vector<int>(m + 1, 1e9));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j1] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int jn1 = j1 + dj1;
                        int jn2 = j2 + dj2;
                        if (jn1 < 0 || jn2 < 0 || jn1 >= m || jn2 >= m)
                            continue;
                        if (j1 == j2)
                            maxi = max(maxi, grid[i][j1] + front[jn1][jn2]);
                        else
                            maxi = max(maxi, grid[i][j1] + grid[i][j2] + front[jn1][jn2]);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    return front[0][m - 1];
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    return sp(n, m, grid);
    // code here
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = solve(r, c, grid);
    cout << result << endl;
    return 0;
}
