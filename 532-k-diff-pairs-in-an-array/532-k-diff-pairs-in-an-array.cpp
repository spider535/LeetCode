class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        set<pair<int,int>> st;
        for(auto &it : nums){
            if(mp.count(it-k))
                st.insert({min(it,it-k),max(it,it-k)});
            if(mp.count(it+k))
                st.insert({min(it,it+k),max(it,it+k)});
            mp[it]++;
        }
        return st.size();
    }
};