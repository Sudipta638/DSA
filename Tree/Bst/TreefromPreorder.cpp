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
TreeNode* slove(vector<int>& pre ,int &i,int ub){
        if(i==pre.size()||pre[i]>ub)  
          return NULL;
        TreeNode*root = new TreeNode(pre[i++]);
        root->left = slove(pre,i,root->val);
        root->right = slove(pre,i,ub);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id =0;
        return slove(preorder,id,INT_MAX);
    }
    int main(){
        vector<int> preorder = {8,5,1,7,10,12};
        TreeNode* root = bstFromPreorder(preorder);
        return 0;
    }