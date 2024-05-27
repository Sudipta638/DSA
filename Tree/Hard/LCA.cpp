#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* slove(TreeNode* root , TreeNode* p, TreeNode*q){
        if(root==NULL||root==p||root==q)
          return root;
        TreeNode* left = NULL;
         if(root->left)
           left = slove(root->left,p,q);
        TreeNode *right =NULL;
           if(root->right)
           right = slove(root->right,p,q);
        if(!left)
          return right;
        else if(!right)
          return left;
        else
          return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return slove(root,p,q);
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
    TreeNode* p = bigTree->left->left->left;
    TreeNode* q = bigTree->left->right->right;
    TreeNode* res = lowestCommonAncestor(bigTree,p,q);
    cout<<res->val;
    return 0;
}
