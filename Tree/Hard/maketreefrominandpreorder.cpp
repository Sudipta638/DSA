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
TreeNode *slove(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{

    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->val];

    int numsLeft = inRoot - inStart;

    root->left = slove(preorder, preStart + 1, preStart + numsLeft,
                       inorder, inStart, inRoot - 1, inMap);

    root->right = slove(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    TreeNode *root = slove(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}