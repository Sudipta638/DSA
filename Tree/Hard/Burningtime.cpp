//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void makeparent(Node *root, unordered_map<Node *, Node *> &parent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            if (it->left)
            {
                parent[it->left] = it;
                q.push(it->left);
            }
            if (it->right)
            {
                parent[it->right] = it;
                q.push(it->right);
            }
        }
    }
}
    Node* searchNode(Node* node, int target) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == target) {
        return node;
    }

    Node* leftSearch = searchNode(node->left, target);
    if (leftSearch) {
        return leftSearch;
    }

    return searchNode(node->right, target);
}
    int minTime(Node* root, int target) 
    {
        //int time =0;
        unordered_map<Node*,Node*>parent;
        makeparent(root,parent);
      //  vector<int>ans;
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        //cout<<parent[target]->val<<endl;
        int dist =0;
        Node*targetNode= searchNode(root,target);
        q.push(targetNode);
        while(!q.empty()){
            int sz = q.size();
            dist++;
            for(int i =0;i<sz;i++){
                auto it=q.front();
                q.pop();
                vis[it]=true;
                if(parent[it]&&!vis[parent[it]]){
                    //cout<<parent[it]->val<<endl;
                    q.push(parent[it]);
                }
                if(it->left&&!vis[it->left]){
                  //if(dist==k)  ans.push_back(it->left->val);
                    q.push(it->left);
                }
                if(it->right&&!vis[it->right]){
                //  if(dist==k)  ans.push_back(it->right->val);
                    q.push(it->right);
                }
            }
            // if(dist==k)
            //   break;
        }
        return dist==0?dist:dist-1;
       
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends