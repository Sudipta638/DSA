// Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. as Geek wants to improve all his skills, he can't do the same activity on two consecutive days, help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

// Example:
// Input:
// n = 3
// point= [[1,2,5],[3,1,1],[3,3,3]]
// Output:
// 11
// Explanation:
// Geek will learn a new move and earn 5 point then on second
// day he will do running and earn 3 point and on third day
// he will do fighting and earn 3 points so, maximum point is 11.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function maximumPoints() which takes the integer n and 2 D array points and returns the maximum point he can earn.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n2)

// Constraint:
// 1 <=  n <= 100000
// 1 <=  point[i] <= 100

#include <bits/stdc++.h>
using namespace std;

// Recursion
int slove(vector<vector<int>> &arr, int i, int j, int n)
{
    if (j >= 3 || i >= n)
    {
        return 0;
    }
    int ans = 0;
    for (int k = 0; k < 3; k++)
    {
        if (i == 0 || k != j)
        {
            ans = max(ans, arr[i][k] + slove(arr, i + 1, k, n));
        }
    }
    return ans;
}

// Tabulation
int slove(vector<vector<int>> &arr, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            int ans = 0;
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 || k != j)
                {
                    ans = max(ans, arr[i][k] + dp[i + 1][k]);
                }
            }
            dp[i][j] = ans;
        }
    }
    return max(max(dp[0][0], dp[0][1]), dp[0][2]);
}
// Space-Optimization
int slove(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> cur(3, 0), front(3, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            int ans = 0;
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 || k != j)
                {
                    ans = max(ans, arr[i][k] + front[k]);
                }
            }
            cur[j] = ans;
        }
        front = cur;
    }
    return *max_element(front.begin(), front.end());
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    return slove(points);
    // Code here
}

int main()
{
    int n = 3;
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int maxPoints = maximumPoints(points, n);
    cout << "Maximum points: " << maxPoints << endl;
    return 0;
}