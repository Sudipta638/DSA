//{ Driver Code Starts
// Initial Template for C++
// Alien Dictionary
// HardAccuracy: 47.81%Submissions: 96K+Points: 8
// Get Internship at GfG by submitting your Entries in: Data Science Blogathon

// banner
// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Example 2:

// Input: 
// N = 3, K = 3
// dict = {"caa","aaa","aab"}
// Output:
// 1
// Explanation:
// Here order of characters is
// 'c', 'a', 'b' Note that words are sorted
// and in the given language "caa" comes before
// "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


// Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
// Expected Space Compelxity: O(K)


// Constraints:
// 1 ≤ N, M ≤ 300
// 1 ≤ K ≤ 26
// 1 ≤ Length of words ≤ 50
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        vector<int>indegree(K,0);
        for(int i =0;i<N-1;i++){
            int j =0;
            int len1 = dict[i].length();
            int len2 = dict[i+1].length();
            while(len1&&len2&&dict[i][j]==dict[i+1][j] ){
                j++;
                len1--;
                len2--;
            }
            if(len1&&len2){
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                indegree[dict[i+1][j]-'a']++;
            }
            
        }
        queue<int>q;
        string ans="";
        for(int i =0;i<K;i++){
            if(indegree[i]==0)
              q.push(i);
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node = it;
            ans+='a'+it;
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)
                  q.push(adjNode);
            }
            
        }
        while(!q.empty()){
            ans+='a'+q.front();
            q.pop();
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends