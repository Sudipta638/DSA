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
void slove(TreeNode *root, int &ans, int &k)
{
    if (root == NULL || k <= 0)
        return;
    slove(root->left, ans, k);
    k--;
    if (k == 0)
    {
        ans = root->val;
        return;
    }
    slove(root->right, ans, k);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    slove(root, ans, k);
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << kthSmallest(root, 1);
    return 0;
}