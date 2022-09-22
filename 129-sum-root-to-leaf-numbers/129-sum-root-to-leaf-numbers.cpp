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
     long long int ans = 0;
     long long int temp = 0;
     void helper(TreeNode* A){
         if(!A)
            return;
        temp *= (long long int)10;
        temp += (long long int)A->val;
        if(A->left == NULL && A->right == NULL){
            ans = (ans + temp);
        }
        helper(A->left);
        helper(A->right);
        temp = temp/10;
     }
    int sumNumbers(TreeNode* root) {
        helper(root);
        return ans;
    }
};