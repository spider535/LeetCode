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
    vector<TreeNode*> allPossibleFBT(int n) {TreeNode* temp = new TreeNode();
        vector<TreeNode*> ans;
        if(n%2 == 0)
            return ans;
        if(n == 1){
            TreeNode* temp = new TreeNode();
            ans.push_back(temp);
        }
        n--;
        for(int i = 1 ; i < n ; i++){
            auto l = allPossibleFBT(i);
            auto r = allPossibleFBT(n-i);
            for(auto &it : l){
                for(auto &ir : r){
                    TreeNode* temp = new TreeNode();
                    temp->left = it;
                    temp->right = ir;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};