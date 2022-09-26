class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        if(k == 0){
            for(auto &it : nums)
                mp[it]++;
            int ans = 0;
            for(auto &it : mp){
                if(it.second > 1)
                    ans++;
            }
            return ans;
        }
        int ans = 0;
        for(auto &it : nums){
            if(mp.count(it))
                continue;
            if(mp.count(it-k))
                ans++;
            if(mp.count(it+k))
                ans++;
            mp[it]++;
        }
        return ans;
    }
};