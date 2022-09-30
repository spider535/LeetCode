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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*,int>> mp;
        TreeNode* root = NULL;
        for(auto &it : descriptions){
            int p = it[0],c = it[1],lr = it[2];
            TreeNode* par;
            if(mp.count(p))
                par = mp[p].first;
            else{
                par = new TreeNode(p);
                mp[p] = {par,-1};
            }
            TreeNode* ch;
            if(mp.count(c))
                ch = mp[c].first;
            else{
                ch = new TreeNode(c);
                mp[c] = {ch,1};
            }
            mp[c].second = 1;
            if(lr == 1)
                par->left = ch;
            else
                par->right = ch;
        }
        for(auto &it : mp){
            if(it.second.second == -1)
                root = it.second.first;
        }
        return root;
    }
};