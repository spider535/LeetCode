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
    int ans = 0;
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return {0,0};
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        int x = left.first+right.first+root->val;
        int y = left.second+right.second+1;
        if(x/y == root->val)
            ans++;
        return {x,y};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};