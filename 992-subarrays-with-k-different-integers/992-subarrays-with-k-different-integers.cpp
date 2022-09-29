class Solution {
public:
    int helper(vector<int>& nums,int k){
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};