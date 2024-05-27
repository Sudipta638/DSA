//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	
  public:
    void dfs(int node , unordered_map<int,bool>& visited, vector<vector<int>>& adj, stack<int>& s) {
        visited[node] = true;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj,s);
            }
        }
        s.push(node);
    }
    void revDfs(int node, unordered_map<int,bool>& visited, vector<vector<int>>& transpose) {
        visited[node] = true;
        for(auto it: transpose[node]) {
            if(!visited[it]) {
                revDfs(it,visited,transpose);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        unordered_map<int,bool>visited;
        stack<int>s;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfs(i,visited,adj,s);
            }
        }
        // transpose
        vector<vector<int>>transpose(V);
        for(int i=0;i<V;i++) {
            visited[i] = false;
            for(auto it: adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        // count
        int count  = 0;
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            if(!visited[top]) {
                count++;
                revDfs(top,visited,transpose);
            }
        }
       return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends