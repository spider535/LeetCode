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
class BSTIterator {
public:
    TreeNode* s;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        s = root;
        while(s && s->left){
            st.push(s);
            s = s->left;
        }
    }
    
    int next() {
        int temp = -1;
        if(s){
            temp = s->val;
            if(s->right){
                s = s->right;
                while(s->left){
                    st.push(s);
                    s = s->left;
                }
            }
            else{
                if(!st.empty()){
                    s = st.top();
                    st.pop();
                }
                else
                    s = NULL;
            }
        }
        return temp;
    }
    
    bool hasNext() {
        return s;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */