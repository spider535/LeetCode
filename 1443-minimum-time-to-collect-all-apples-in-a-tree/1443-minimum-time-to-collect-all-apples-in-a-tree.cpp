class Solution {
public:
    int ans = 0;
    bool dfs(vector<int> adj[],int i,vector<bool> &app,int par){
        bool flag = false;
        if(app[i])
            flag = true;
        for(auto &it : adj[i]){
            if(it != par){
                flag = flag | dfs(adj,it,app,i);
            }
        }
        if(flag && i != 0)
            ans += 2;
        return flag;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj,0,hasApple,-1);
        return ans;
    }
};