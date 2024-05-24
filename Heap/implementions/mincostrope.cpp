//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n==1)
          return 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(int i =0;i<n;i++){
            pq.push(arr[i]);
        }
        long long ans =0;
        while(pq.size()>1){
            long long int min1 = pq.top();
            pq.pop();
            long long int min2 =pq.top();;
            pq.pop();
            ans+=(min1+min2);
            pq.push(min1+min2);
        }
       // pq.pop();
        // while(!pq.empty()){
        //     ans+=pq.top();
        //     pq.pop();
        // }
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends