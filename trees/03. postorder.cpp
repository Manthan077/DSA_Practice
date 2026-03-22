#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

// Recursive approach

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


// Iterative approach

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);

        if (root->left != nullptr) st.push(root->left);
        if (root->right != nullptr) st.push(root->right);
    }
    reverse(res.begin(), res.end());
    return res;
}
