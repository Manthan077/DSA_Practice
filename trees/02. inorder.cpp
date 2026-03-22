#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

// Recursive approach

void inorder(TreeNode* root,vector<int>& res){
    if(root==nullptr) return;

    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root,res);
    return res;
}


// Iterative approach

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
