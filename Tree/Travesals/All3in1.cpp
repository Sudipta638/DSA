#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
vector<vector<int>> getTreeTraversal(TreeNode *root){
    stack<pair<TreeNode*,int>>st;
    st.push({root, 1});
    vector<int>pre,in,post;
    while(!st.empty()){
         auto it = st.top();
         st.pop();
         int rank = it.second;
         TreeNode* cur = it.first;
         switch(rank){
           case 1:
              pre.push_back(cur->data);
              rank++;
              st.push({cur,rank});
              if(cur->left)
                st.push({cur->left,1});
              break;
            case 2:
              in.push_back(cur->data);
              rank++;
              st.push({cur,rank});
              if(cur->right)
                st.push({cur->right,1});
             break;
            case 3:
              post.push_back(cur->data);
              break;
         }
            
    }
    vector<vector<int>>ans;
    ans.push_back(in);
      ans.push_back(pre);
    ans.push_back(post);
    return ans;
    // Write your code here.
}

int main(){
    // Create a big tree
    TreeNode *bigTree = new TreeNode(10);
    bigTree->left = new TreeNode(5);
    bigTree->right = new TreeNode(15);
    bigTree->left->left = new TreeNode(3);
    bigTree->left->right = new TreeNode(7);
    bigTree->right->left = new TreeNode(12);
    bigTree->right->right = new TreeNode(18);
    bigTree->left->left->left = new TreeNode(2);
    bigTree->left->left->right = new TreeNode(4);
    bigTree->left->right->left = new TreeNode(6);
    bigTree->left->right->right = new TreeNode(8);
    bigTree->right->left->left = new TreeNode(11);
    bigTree->right->left->right = new TreeNode(13);
    bigTree->right->right->left = new TreeNode(16);
    bigTree->right->right->right = new TreeNode(20);
    vector<vector<int>> res = getTreeTraversal(bigTree);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}