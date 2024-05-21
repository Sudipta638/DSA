// Minimal Cost
// MediumAccuracy: 51.08%Submissions: 14K+Points: 4
// Find better job opportunities this summer via Job-A-Thon Hiring Challenge!

// banner
// There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone N.

// Example 1:
// Input:
// n = 5, k = 3
// heights = {10, 30, 40, 50, 20}
// Output:
// 30
// Explanation:
// Geek will follow the path 1->2->5, the total cost
// would be | 10-30| + |30-20| = 30, which is minimum
// Example 2:

// Input:
// n = 3, k = 1
// heights = {10,20,10}
// Output:
// 20
// Explanation:
// Geek will follow the path 1->2->3, the total cost
// would be |10 - 20| + |20 - 10| = 20.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minimizeCost() which takes the array height, and integer n, and integer k and returns the minimum energy that is lost.

// Expected Time Complexity: O(n*k)
// Expected Space Complexity: O(n)

// Constraint:
// 2 <= n <= 105
// 1 <= k <= 100
// 1 <= heights[i] <= 104

#include <bits/stdc++.h>
using namespace std;

// Bottom-up Apporach
int slove(vector<int> &height, int i, int n, int k)
{
    if (i >= n - 1)
        return 0;
    int ans = INT_MAX;
    for (int j = i + 1; j < min(i + k + 1, n); j++)
    {

        ans = min(ans, abs(height[j] - height[i]) + slove(height, j, n, k));
    }
    return ans;
}

// Recursion
int slove(vector<int> &height, int n, int k)
{

    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        int ans = INT_MAX;
        for (int j = i + 1; j < min(i + k + 1, n); j++)
        {

            ans = min(ans, abs(height[j] - height[i]) + dp[j]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
// Memorization

int minimizeCost(vector<int> &height, int n, int k)
{
    return slove(height, n, k);
    // Code here
}

int main()

{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int result = minimizeCost(heights, n, 3);
    cout << "Minimum energy: " << result << endl;
    return 0;
}
