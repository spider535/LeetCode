class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> ans(n+1);
        unordered_map<int,vector<int>> mp;
        for(auto &it : pairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int ind = -1;
        for(auto &it : mp){
            if(it.second.size() == 1){
                ind = it.first;
                break;
            }
        }
        ans[0] = ind;
        ind = mp[ind][0];
        for(int i = 1 ; i <= n ; i++){
            ans[i] = ind;
            if(mp[ind][0] != ans[i-1])
                ind = mp[ind][0];
            else if(i != n)
                ind = mp[ind][1];
        }
        return ans;
    }
};