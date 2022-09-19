class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int x = 0;
        unordered_map<int,int> mp;
        mp[0] = -n;
        for(auto &it : wall){
            int x = 0;
            for(auto &ir : it){
                mp[x]++;
                x += ir;
            }
        }
        int ans = 0;
        for(auto &it : mp){
            ans = max(ans,it.second);
        }
        return n-ans;
    }
};