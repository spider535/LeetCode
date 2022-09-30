class Solution {
public:
    int dfs(vector<int> adj[],int i,int par){
        int ans = 1;
        for(auto &it : adj[i]){
            if(it != par)
                ans += dfs(adj,it,i);
        }
        return ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int> st;
        for(auto &it : restricted)
            st.insert(it);
        vector<int> adj[n];
        for(auto &it : edges){
            if(st.count(it[0]) || st.count(it[1]))
                continue;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,0,-1);
    }
};