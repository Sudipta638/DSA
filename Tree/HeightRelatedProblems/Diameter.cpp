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
int slove(TreeNode *root, int &maxdepth)
{
    if (root == NULL)
        return 0;
    int lh = slove(root->left, maxdepth);
    int rh = slove(root->right, maxdepth);
    int depth = lh + rh;
    maxdepth = max(maxdepth, depth);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int max = 0;
    slove(root, max);
    return max;
}
int main()
{
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
    cout << diameterOfBinaryTree(bigTree);
    return 0;
}