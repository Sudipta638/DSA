// Minimum Multiplications to reach End
// MediumAccuracy: 48.94%Submissions: 87K+Points: 4
// Get Internship at GfG by submitting your Entries in: Data Science Blogathon

// banner
// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Example 1:

// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30
// Example 2:

// Input:
// arr[] = {3, 4, 65}
// start = 7, end = 66175
// Output:
// 4
// Explanation:
// Step 1: 7*3 = 21 % 100000 = 21 
// Step 2: 21*3 = 63 % 100000 = 63 
// Step 3: 63*65 = 4095 % 100000 = 4095 
// Step 4: 4095*65 = 266175 % 100000 = 66175
// Your Task:
// You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

// Expected Time Complexity: O(105)
// Expected Space Complexity: O(105)

// Constraints:

// 1 <= n <= 104
// 1 <= arr[i] <= 104
// 1 <= start, end < 105

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int maxnode = 100000;
        vector<int>dist(maxnode,1e9);
        queue<pair<int, int>> pq;
        dist[start] = 0;
        pq.push({start,0});
        while(!pq.empty()){
            auto it = pq.front();
            int node = it.first;
            int steps =it.second;
            pq.pop();
            // if(node == end)
            //   return steps;
            for(auto it:arr){
                int num = (node*it)%maxnode;
                if(steps+1<dist[num]){
                    dist[num]= steps+1;
                    pq.push({num,dist[num]});
                }
            }
        }
        return dist[end]==1e9?-1:dist[end];
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends