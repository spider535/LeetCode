class TrieNode{
public:
    vector<TrieNode*> child;
    bool we;
    TrieNode(){
        child.resize(26,NULL);
        we = false;
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode();
public:
    void insert(string &word){
        TrieNode* t = root;
        for(auto &it : word){
            if(!t->child[it-'a']){
                // cout<<it<<" ";
                t->child[it-'a'] = new TrieNode();
            }
            t = t->child[it-'a'];
        }
        t->we = true;
    }
    int search(string &word,int i){
        int n = word.size();
        if(i == n)
            return 0;
        TrieNode* t = root;
        while(i < n){
            if(!t->child[word[i]-'a'])
                return 0;
            t = t->child[word[i]-'a'];
            if(t->we){
                int x = search(word,i+1);
                if(x > 0)
                    return x+1;
            }
            i++;
        }
        return t->we;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto &it : words){
            insert(it);
        }
        for(auto &it : words){
            if(search(it,0) > 1)
                ans.push_back(it);
        }
        return ans;
    }
};