/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool BST(TreeNode* r,long long L,long long R){
        if(!r) return 1;
        if(r->val<=L || r->val>=R) return 0;
        return BST(r->left,L,r->val) && BST(r->right,r->val,R);
    }
    
    bool isValidBST(TreeNode* root) {
        return BST(root,LLONG_MIN,LLONG_MAX);        
    }
};