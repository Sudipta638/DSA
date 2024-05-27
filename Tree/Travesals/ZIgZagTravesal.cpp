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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool LtoR = true;
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        while (size--)
        {
            auto it = q.front();
            q.pop();
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
            level.push_back(it->val);
        }
        if (!LtoR)
            reverse(level.begin(), level.end());
        ans.push_back(level);
        LtoR = !LtoR;
    }
    return ans;
}

int main()
{
    // Create the tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Perform zigzag level order traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    for (const auto &level : result)
    {
        for (const auto &val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
