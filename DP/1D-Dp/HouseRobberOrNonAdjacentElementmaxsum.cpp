// 198. House Robber
// Solved
// Medium
// Topics
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400





#include <bits/stdc++.h>
using namespace std;
// Recursion
int slove(vector<int> &nums, int i, int n)
{
    if (i > n - 1)
        return 0;
    int skip = slove(nums, i + 1, n);
    int non_skip = nums[i] + slove(nums, i + 2, n);
    return max(skip, non_skip);
}

// Bottom-Up
int slove(vector<int> &nums, int n)
{
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int skip = dp[i + 1];
        int non_skip = nums[i] + dp[i + 2];
        dp[i] = max(skip, non_skip);
    }
    return dp[0];
}

// Memorization
int solve(vector<int> &nums, int i, vector<int> &memo)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    int skip = solve(nums, i + 1, memo);
    int non_skip = nums[i] + solve(nums, i + 2, memo);
    memo[i] = max(skip, non_skip);
    return memo[i];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> memo(n, -1);
    return solve(nums, 0, memo);
}
// tabulation
int slove(vector<int> &nums)
{
    int n = nums.size();
    int front = 0;
    int front2 = 0;
    int cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur = max(front, nums[i] + front2);
        front2 = front;
        front = cur;
    }
    return front;
}
int rob(vector<int> &nums)
{
    // int n = nums.size();
    return slove(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int maxAmount = rob(nums);
    cout << "Maximum amount of money you can rob tonight: " << maxAmount << endl;
    return 0;
}