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
void makeparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            if (it->left)
            {
                parent[it->left] = it;
                q.push(it->left);
            }
            if (it->right)
            {
                parent[it->right] = it;
                q.push(it->right);
            }
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (k == 0)
        return {target->val};
    unordered_map<TreeNode *, TreeNode *> parent;
    makeparent(root, parent);
    vector<int> ans;
    unordered_map<TreeNode *, bool> vis;
    queue<TreeNode *> q;
    // cout<<parent[target]->val<<endl;
    int dist = 0;
    q.push(target);
    while (!q.empty())
    {
        int sz = q.size();
        dist++;
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            vis[it] = true;
            if (parent[it] && !vis[parent[it]])
            {
                // cout<<parent[it]->val<<endl;
                if (dist == k)
                    ans.push_back(parent[it]->val);
                q.push(parent[it]);
            }
            if (it->left && !vis[it->left])
            {
                if (dist == k)
                    ans.push_back(it->left->val);
                q.push(it->left);
            }
            if (it->right && !vis[it->right])
            {
                if (dist == k)
                    ans.push_back(it->right->val);
                q.push(it->right);
            }
        }
        if (dist == k)
            break;
    }
    return ans;
}
int main()
{
    // Create the tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Set the target node and distance
    TreeNode *target = root->left;
    int k = 2;

    // Call the distanceK function
    vector<int> result = distanceK(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up the memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}