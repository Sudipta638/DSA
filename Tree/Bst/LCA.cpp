#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* slove(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
          return NULL;
        if(root->val>p->val&&root->val>q->val){
           // cout<<root->val<<endl;
           return slove(root->left,p,q);
        }
        if(root->val<p->val&&root->val<q->val){
            //cout<<root->val<<endl;
            return slove(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return slove(root,p,q);
    }
    int main(){
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        TreeNode *p = new TreeNode(2);
        TreeNode *q = new TreeNode(8);
        cout<<lowestCommonAncestor(root,p,q)->val;
        return 0;
    }