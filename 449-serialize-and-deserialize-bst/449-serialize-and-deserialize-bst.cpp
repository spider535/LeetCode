/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string ans = "";
        ans += to_string(root->val)+" ";
        ans += serialize(root->left);
        ans += serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s_data) {
        vector<int> data;
        int j = 0;
        int n = s_data.size();
        while(j < n){
            while(j < n && s_data[j] == ' ')
                j++;
            string temp;
            while(j < n && s_data[j] != ' '){
                temp.push_back(s_data[j++]);
            }
            if(temp != "")
                data.push_back(stoi(temp));
        }
        if(data.empty())
            return NULL;
        stack<TreeNode*> st;
        TreeNode* ans = new TreeNode(data[0]);
        TreeNode* t = ans;
        st.push(ans);
        for(int i = 1 ; i < data.size() ; i++){
            while(!st.empty() && data[i] > st.top()->val){
                t = st.top();
                st.pop();
            }
            if(data[i] < t->val){
                t->left = new TreeNode(data[i]);
                t = t->left;
            }
            else{
                t->right = new TreeNode(data[i]);
                t = t->right;
            }
            st.push(t);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;