#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> pre;
    if (!root)
        return pre;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        auto it = st.top();
        pre.push_back(it->val);
        st.pop();
        if (it->right)
            st.push(it->right);
        if (it->left)
            st.push(it->left);
    }
    return pre;
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
    vector<int> res = preorderTraversal(bigTree);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
