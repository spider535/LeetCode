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
    int helper(TreeNode* root,int x,int l){
        if(!root)
            return 0;
        if(!root->left && !root->right){
            if(x+root->val >= l)
                return 1;
            return 0;
        }
        int left = helper(root->left,x+root->val,l);
        int right = helper(root->right,x+root->val,l);
        if(left == 0)
            root->left = NULL;
        if(right == 0)
            root->right = NULL;
        if(left || right){
            return 1;
        }
        return 0;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int x = helper(root,0,limit);
        if(x)
            return root;
        return NULL;
    }
};