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

// Construct binary tree from preorder and inorder traversals

class Solution {
public:

    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,
                    vector<int>& inorder,int inStart,int inEnd,
                    unordered_map<int,int>& map) {
        if(preStart>preEnd || inStart>inEnd) return nullptr;

        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=map[root->val];
        int numsLeft=inRoot-inStart;

        root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,map);
        root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,map);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
    }
};


// /Construct binary tree from postorder and inorder traversals

class Solution {
public:

    TreeNode* build(vector<int>& postorder,int postStart,int postEnd,
                    vector<int>& inorder,int inStart,int inEnd,                          
                    unordered_map<int,int>&map){
        if(postStart>postEnd || inStart>inEnd) return nullptr;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=map[root->val];
        int numsLeft=inRoot-inStart;

        root->left=build(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,
        map);
        root->right=build(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,map);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,map);
    }
};
