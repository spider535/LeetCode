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
    unordered_map<TreeNode*,vector<int>> dp;
    int helper(TreeNode* root,bool t){
        if(!root)
            return 0;
        if(!dp.count(root))
            dp[root].resize(2,-1);
        if(dp[root][t] != -1)
            return dp[root][t];
        if(t){
            return dp[root][t] = max(root->val+helper(root->left,!t)+helper(root->right,!t),helper(root->left,t)+helper(root->right,t));
        }
        return dp[root][t] = helper(root->left,!t)+helper(root->right,!t);
    }
    int rob(TreeNode* root) {
        return helper(root,1);
    }
};