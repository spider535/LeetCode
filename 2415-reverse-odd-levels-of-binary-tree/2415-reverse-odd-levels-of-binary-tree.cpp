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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> qe;
        stack<int> st;
        qe.push(root);
        int x = 0;
        while(!qe.empty()){
            int n = qe.size();
            while(n--){
                auto t = qe.front();
                qe.pop();
                if(x&1){
                    t->val = st.top();
                    st.pop();
                }
                if(t->left){
                    qe.push(t->left);
                    if(!(x&1))
                        st.push(t->left->val);
                }
                if(t->right){
                    qe.push(t->right);
                    if(!(x&1))
                        st.push(t->right->val);
                }
            }
            x++;
        }
        return root;
    }
};