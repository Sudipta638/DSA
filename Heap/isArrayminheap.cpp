//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool slove(int arr[],int n,int i){
            if(i>=n)
              return true;
        
            int largest =i;
            int left = 2*i+1;
            int right = 2*i+2;
            if(arr[largest]<arr[left])
              return false;
            bool isleft = slove(arr,n,left);
            if(arr[largest]<arr[right])
               return false;
            bool isright = slove(arr,n,right);
            return isright&& isleft;
    }
    bool isMaxHeap(int arr[], int n)
    {
        return slove(arr, n,0);
        // Your code goes here
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends