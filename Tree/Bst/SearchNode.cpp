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
TreeNode *slove(TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return slove(root->left, val);
    return slove(root->right, val);
}
TreeNode *searchBST(TreeNode *root, int val)
{
    return slove(root, val);
}