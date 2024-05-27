#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 int widthOfBinaryTree(TreeNode* root) {
        uint64_t maxwidth =0;
        queue<pair<TreeNode*,uint64_t>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            TreeNode*firstlevelnode = it.first;
            uint64_t min_index = it.second;
            cout<<min_index<<endl;
            uint64_t sz = q.size();
            uint64_t first=0;
           uint64_t last =0;
            for(int i=0;i<sz;i++){
                auto it1 = q.front();
                q.pop();
                TreeNode* temp = it1.first;
                uint64_t cur_index = it1.second;
                  cur_index -= min_index;
                if(i==0)
                  first = cur_index;
                if(i==sz-1)
                  last = cur_index;
                if(temp->left)
                  q.push({temp->left,cur_index*2+1});
                if(temp->right)
                  q.push({temp->right,cur_index*2+2});
            } 
            maxwidth = max(maxwidth,last-first+1);

        }
        return maxwidth;
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
        int res = widthOfBinaryTree(bigTree);
        cout<<res;
        return 0;
    }