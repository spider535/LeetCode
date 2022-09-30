class Solution {
public:
    vector<vector<int>> ans;
    void dfs(unordered_map<int,stack<int>> &mp,int node){
        while(!mp[node].empty()){
            int y = mp[node].top();
            mp[node].pop();
            dfs(mp,y);
            ans.push_back({node,y});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,pair<int,int>> degree;
        unordered_map<int,stack<int>> mp;
        int n = pairs.size();
        for(auto &it : pairs){
            mp[it[0]].push(it[1]);
            degree[it[0]].second++;
            degree[it[1]].first++;
        }
        int ind;
        for(auto &it : degree){
            if(it.second.first < it.second.second){
                ind = it.first;
                break;
            }
            else if(it.second.first == it.second.second){
                ind = it.first;
            }
        }
        dfs(mp,ind);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};