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
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->val > val)
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                // cout<<temp->val<<endl;
                temp->left = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode *newRoot = insertIntoBST(root, 5);
    return 0;
    
}