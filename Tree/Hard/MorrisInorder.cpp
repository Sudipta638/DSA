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
vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *cur = root;
    vector<int> inorder;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }
            if (temp->right == NULL)
            {
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    return inorder;
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
    vector<int> res = inorderTraversal(bigTree);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}