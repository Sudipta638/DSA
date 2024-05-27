#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        if (root == NULL)
            return s;
        q.push(root);
        s += to_string(root->val);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* left = it->left;
            left ? s += ("," + to_string(left->val)) : s += (",#");
            if (left)
                q.push(left);
            TreeNode* right = it->right;
            right ? s += ("," + to_string(right->val)) : s += (",#");
            if (right)
                q.push(right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
           // cout<<str<<endl;
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }

    int main(){
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
        string res = serialize(bigTree);
        cout<<res<<endl;
        TreeNode* root = deserialize(res);
        cout<<root->val<<endl;
        return 0;
    }