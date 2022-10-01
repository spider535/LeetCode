class Solution {
public:
    vector<vector<int>> ans;
    vector<int> disc,low;
    int timer = 0;
    void dfs(vector<int> adj[],int u,int par){
        disc[u] = timer;
        low[u] = timer++;
        for(auto &v : adj[u]){
            if(v == par)
                continue;
            if(disc[v] == -1){
                dfs(adj,v,u);
                low[u] = min(low[u],low[v]);
            }
            else
                low[u] = min(low[u],disc[v]);
            if(low[v] > disc[u])
                ans.push_back({u,v});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto &it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        disc.resize(n,-1);
        low.resize(n,-1);
        dfs(adj,0,-1);
        return ans;
    }
};