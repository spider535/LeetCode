class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0, cash = 0;
        for(auto &it : transactions){
            ans += 1ll*max(0,it[0]-it[1]);
            cash = 1ll*max(cash,1ll*min(it[0],it[1]));
        }
        return ans+cash;
    }
};