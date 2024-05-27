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
bool slove(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    bool check = p->val == q->val;
    if (!check)
        return false;
    bool leftcheck = slove(p->left, q->left);
    if (!leftcheck)
        return false;
    bool rightcheck = slove(p->right, q->right);
    if (!rightcheck)
        return false;
    return check && leftcheck && rightcheck;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    return slove(p, q);
}

int main()
{
    // Create two binary trees
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Check if the two trees are the same
    bool result = isSameTree(tree1, tree2);

    // Print the result
    if (result)
    {
        cout << "The two trees are the same." << endl;
    }
    else
    {
        cout << "The two trees are not the same." << endl;
    }

    // Clean up memory
    delete tree1;
    delete tree2;

    return 0;
}
