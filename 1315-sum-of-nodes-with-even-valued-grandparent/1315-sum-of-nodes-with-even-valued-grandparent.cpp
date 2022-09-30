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
    void helper(TreeNode* root,int x){
        if(!root)
            return;
        if(x > 1)
            ans += root->val;
        if(x == 2)
            x = -1;
        if(x == 3)
            x = 1;
        if(root->val % 2 == 0){
            x += 2;
        }
        else if(x != -1)
            x++;
        helper(root->left,x);
        helper(root->right,x);
    }
    int sumEvenGrandparent(TreeNode* root) {
        helper(root,-1);
        return ans;
    }
};