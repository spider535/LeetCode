class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int ans = 0;
        int temp = 0;
        for(auto &it : nums){
            if(it == mx)
                temp++;
            else
                temp = 0;
            ans = max(ans,temp);
        }
        return ans;
    }
};