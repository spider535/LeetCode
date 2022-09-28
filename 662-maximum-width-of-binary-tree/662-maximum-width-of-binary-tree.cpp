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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,long long int>> qe;
        qe.push({root,0});
        while(!qe.empty()){
            int n = qe.size();
            int st = qe.front().second;
            int ed = qe.back().second;
            ans = max(ans,ed-st+1);
            while(n--){
                TreeNode* t = qe.front().first;
                long long int v = qe.front().second-st;
                qe.pop();
                if(t->left)
                    qe.push({t->left,2*v+1});
                if(t->right)
                        qe.push({t->right,2*v+2});
            }
            
        }
        return ans;
    }
};