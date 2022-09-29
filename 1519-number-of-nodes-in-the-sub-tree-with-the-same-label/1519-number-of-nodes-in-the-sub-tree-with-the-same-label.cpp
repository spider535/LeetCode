class Solution {
public:
    vector<int> ans;
    vector<int> dfs(vector<int> adj[],int i,string &lab,int par){
        vector<int> temp(26,0);
        temp[lab[i]-'a']++;
        for(auto &it : adj[i]){
            if(it != par){
                vector<int> tt = dfs(adj,it,lab,i);
                for(int i = 0 ; i < 26 ; i++){
                    temp[i] += tt[i];
                }
            }
        }
        ans[i] = temp[lab[i]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        ans.resize(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj,0,labels,-1);
        return ans;
    }
};