//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node{
    public:
    int data;
    int row;
    int col;
    Node(int data,int r ,int c){
        this->data= data;
        row =r;
        col =c;
    }
};
class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data >b->data;
    }
};
class Solution
{
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*,vector<Node*>,compare>pq;
        for(int i=0;i<K;i++){
            Node *newnode = new Node(arr[i][0],i,0);
            pq.push(newnode);
        }
        vector<int>ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it->data);
            int row = it->row;
            int col = it->col;
            col++;
            if(col<arr[row].size()){
                //col++;
                Node *newnode = new Node(arr[row][col],row,col);
                pq.push(newnode);
            }
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends