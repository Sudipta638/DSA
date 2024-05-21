
#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(W + 1, 0);

    // Base condition: Fill in 'prev' for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = prev[cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + prev[cap - wt[ind]];
            }

            // Update 'prev' for the current capacity
            prev[cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the 'prev' vector
    return prev[W];
}


     int slove(int W , int wt[],int val[],int n ){
     vector<int>front(W+1,0),cur(W+1,0);
	   
	    front[0] =0;
	    for(int i =n-1 ;i>=0;i--){
	        //cur[0]=0;
	        for(int j = W;j>=0;j--){
	            int take =0 ,non_take =0;
	            if(j>=wt[i])
	             take = front[j-wt[i]]+ val[i];
	             non_take = front[j];
	            cur[j] =max(take,non_take);
	        }
	        front = cur;
	    }
	    return front[W];
     }
int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}

