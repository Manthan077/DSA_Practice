#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

void postorder(TreeNode* root,vector<int>& res){
    if(root==nullptr) return;

    postorder(root->left,res);
    postorder(root->right,res);             
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root,res);
    return res;
}
