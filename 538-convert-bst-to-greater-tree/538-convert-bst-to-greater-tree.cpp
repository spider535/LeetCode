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
    int x = 0;
    void helper(TreeNode* root,int y){
        if(!root)
            return ;
        helper(root->right,y);
        root->val += x;
        x = root->val;
        helper(root->left,root->val);
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root,0);
        return root;
    }
};