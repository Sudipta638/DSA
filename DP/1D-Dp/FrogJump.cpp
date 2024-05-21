//  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

// Example:
// Input:
// n = 4
// height = {10 20 30 10}
// Output:
// 20
// Explanation:
// Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
// Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
// so, total energy lost is 20 which is the minimum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraint:
// 1<=n<=100000
// 1<=height[i]<=1000

#include <bits/stdc++.h>
using namespace std;

// Tabulation Method
int slove(vector<int> &heights, int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        int one_step = abs(heights[i + 1] - heights[i]) + dp[i + 1];
        int two_step = i < n - 2 ? abs(heights[i + 2] - heights[i]) + dp[i + 2] : INT_MAX;
        dp[i] = min(one_step, two_step);
    }
    return dp[0];
}

// Space-Optimization
int slove(vector<int> &heights)
{
    int n = heights.size();
    int front = 0;
    int cur = 0;
    int front2 = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int one_step = abs(heights[i + 1] - heights[i]) + front;
        int two_step = i < n - 2 ? abs(heights[i + 2] - heights[i]) + front2 : INT_MAX;
        cur = min(one_step, two_step);
        front2 = front;
        front = cur;
    }
    return front;
}

// Recursion
int slove(vector<int> &heights, int i, int n)
{
    if (i >= n - 1)
        return 0;
    int one_step = abs(heights[i + 1] - heights[i]) + slove(heights, i + 1, n);
    int two_step = i < n - 2 ? abs(heights[i + 2] - heights[i]) + slove(heights, i + 2, n) : INT_MAX;
    return min(one_step, two_step);
}




// Memorization
int slove(vector<int> &heights, int i, int n, vector<int> &memo)
{
    if (i >= n - 1)
        return 0;
    if (memo[i] != -1)
        return memo[i];
    int one_step = abs(heights[i + 1] - heights[i]) + slove(heights, i + 1, n, memo);
    int two_step = i < n - 2 ? abs(heights[i + 2] - heights[i]) + slove(heights, i + 2, n, memo) : INT_MAX;
    memo[i] = min(one_step, two_step);
    return memo[i];
}

int slove(vector<int> &heights, int n)
{
    vector<int> memo(n, -1);
    return slove(heights, 0, n, memo);
}
// Main Code
int minimumEnergy(vector<int> &height, int n)
{
    return slove(height);

    // Code here
}

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int result = minimumEnergy(heights, n);
    cout << "Minimum energy: " << result << endl;
    return 0;
}
