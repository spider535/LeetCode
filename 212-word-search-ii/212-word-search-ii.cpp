class TrieNode{
public:
    bool ed;
    vector<TrieNode*> child;
    TrieNode(){
        ed = false;
        child.resize(26,NULL);
    }
};
class Trie{
private:
    TrieNode* root;
public:
    TrieNode* getroot(){
        return root;
    }
    Trie(vector<string>& word){
        root = new TrieNode();
        for(auto &it : word){
            add(it);
        }
    }
    void add(string& s){
        TrieNode* curr = root;
        for(auto &it : s){
            if(!curr->child[it-'a'])
                curr->child[it-'a'] = new TrieNode();
            curr = curr->child[it-'a'];
        }
        curr->ed = true;
    }
};
class Solution {
public:
    void helper(vector<vector<char>>& board,int i,int j,int m,int n,TrieNode* root,string temp,set<string>& ans){
        if(i<0 || j<0 || i>=m || j >=n || board[i][j] == ' ')
            return;
        if(root->child[board[i][j]-'a']){
            root = root->child[board[i][j]-'a'];
            temp += board[i][j];
            if(root->ed)
                ans.insert(temp);
            char x = board[i][j];
            board[i][j] = ' ';
            helper(board,i+1,j,m,n,root,temp,ans);
            helper(board,i,j+1,m,n,root,temp,ans);
            helper(board,i-1,j,m,n,root,temp,ans);
            helper(board,i,j-1,m,n,root,temp,ans);
            board[i][j] = x;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getroot();
        set<string> ans;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                helper(board,i,j,m,n,root,"",ans);
            }
        }
        vector<string> ans_(ans.begin(),ans.end());
        return ans_;
    }
};