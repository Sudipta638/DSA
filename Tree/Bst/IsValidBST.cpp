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
bool slove(TreeNode *root, long long int lb, long long int ub)
{
    if (root == NULL)
        return true;
    if (lb >= root->val || ub <= root->val)
        return false;
    return slove(root->left, lb, root->val) && slove(root->right, root->val, ub);
}
bool isValidBST(TreeNode *root)
{
    long long int lb = INT64_MIN, ub = INT64_MAX;
    return slove(root, lb, ub);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << isValidBST(root);
    return 0;
}