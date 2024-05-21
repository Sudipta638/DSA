// Perfect Sum Problem
// MediumAccuracy: 20.58%Submissions: 258K+Points: 4
// Find better job opportunities this summer via Job-A-Thon Hiring Challenge!

// banner
// Given an array arr of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7.

// Example 1:

// Input:
// N = 6
// arr = [5, 2, 3, 10, 6, 8]
// sum = 10
// Output:
// 3
// Explanation:
// {5, 2, 3}, {2, 8}, {10} are possible subsets.
// Example 2:
// Input:
// N = 5
// arr = [2, 5, 1, 4, 3]
// sum = 10
// Output:
// 3
// Explanation:
// {2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.
// Your Task:
// You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr and sum as input parameters and returns an integer value.

// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Constraints:
// 1 ≤ N*sum ≤ 106
// 0 ≤ arr[i] ≤ 106

#include <bits/stdc++.h>
using namespace std;
int perfectSum(int arr[], int n, int sum)
{
    vector<int> front(sum + 1, 0), cur(sum + 1, 0);
    int mod = 1e9 + 7;
    // if(arr[n-1]<=sum)
    //    front[arr[n-1]] =1;
    front[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j >= arr[i])
                cur[j] = (front[j - arr[i]] + front[j]) % mod;
            else
                cur[j] = front[j];
        }
        front = cur;
    }

    return front[sum];
    // Your code goes here
}