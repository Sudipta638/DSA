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

class BSTIterator {
private:
    stack<TreeNode*> st;
    stack<TreeNode*>Revst;
    void helper1(TreeNode* root){
        if(root==NULL){
            return ;
        }
        while(root){
            st.push(root);
            root=root->left;
        }
        return ;
    }
    void helper2(TreeNode* root){
        if(root==NULL){
            return ;
        }
        while(root){
            Revst.push(root);
            root=root->right;
        }
        return ;
    }    
public:
    TreeNode *node;
    BSTIterator(TreeNode* root) {
        node=root;
        helper1(root);
        helper2(root);
    }
    
    int next() {
        TreeNode * a=st.top();
        st.pop();
        if(a->right){
            helper1(a->right);
        }
        return a->val;
    }
    int prev(){
        TreeNode * a=Revst.top();
        Revst.pop();
        if(a->left){
            helper2(a->left);
        }
        return a->val;      
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator inorder(root);
        BSTIterator Revinorder(root);

        int a=inorder.next();
        int b=Revinorder.prev();
        while(a < b){
            if(a+b < k){
                a=inorder.next();
            }
            else if(a+b > k){
                b=Revinorder.prev();
            }
            else{
                return true;
            }
        }
        return false;

    }
};