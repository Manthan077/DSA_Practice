#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

// Recursive approach

void preorder(TreeNode* root,vector<int>& res){
    if(root==nullptr) return;

    res.push_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root,res);
    return res;
}


// Iterative approach

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);

        if (root->right != nullptr) st.push(root->right);
        if (root->left != nullptr) st.push(root->left);
    }
    return res;
}
