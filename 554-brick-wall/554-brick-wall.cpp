class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int x = 0;
        for(auto &it : wall[0])
            x += it;
        unordered_map<int,int> mp;
        mp[0] = -n;
        mp[x] = -n;
        for(auto &it : wall){
            int x = 0;
            for(auto &ir : it){
                x += ir;
                mp[x]++;
            }
        }
        int ans = 0;
        for(auto &it : mp){
            ans = max(ans,it.second);
        }
        return n-ans;
    }
};