class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<int> degree(n,0);
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int> qe;
        for(int i = 0 ; i < n ; i++){
            if(degree[i] == 1)
                qe.push(i);
        }
        vector<int> ans;
        while(!qe.empty()){
            ans.clear();
            int n = qe.size();
            while(n--){
                int x = qe.front();
                qe.pop();
                degree[x] = 0;
                ans.push_back(x);
                for(auto &it : adj[x]){
                    degree[it]--;
                    if(degree[it] == 1)
                        qe.push(it);
                }
            }
        }
        return ans;
    }
};