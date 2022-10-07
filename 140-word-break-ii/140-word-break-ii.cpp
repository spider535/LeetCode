class TrieNode{
public:
    vector<TrieNode*> child;
    bool we = false;
    TrieNode(){
        child.resize(26,NULL);
        we = false;
    }
};
class Solution {
    TrieNode* root = new TrieNode();
public:
    void insert(string &word){
        TrieNode* t = root;
        for(auto &it : word){
            if(!t->child[it-'a'])
                t->child[it-'a'] = new TrieNode();
            t = t->child[it-'a'];
        }
        t->we = true;
    }
    vector<vector<string>> dp;
    vector<string> helper(string &s,int i,int n){
        if(i == n)
            return {};
        if(dp[i][0] != "$")
            return dp[i];
        TrieNode* t = root;
        string temp;
        vector<string> ans;
        for(int k = i ; k < n ; k++){
            temp.push_back(s[k]);
            if(!t->child[s[k]-'a'])
                return dp[i] = ans;
            t = t->child[s[k]-'a'];
            if(t->we){
                vector<string> x = helper(s,k+1,n);
                for(auto &it : x){
                    ans.push_back(temp+" "+it);
                }
            }
        }
        if(t->we){
            ans.push_back(temp);
        }
        return dp[i] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        for(auto &it : wordDict){
            insert(it);
        }
        dp.resize(n,{"$"});
        return helper(s,0,n);
    }
};