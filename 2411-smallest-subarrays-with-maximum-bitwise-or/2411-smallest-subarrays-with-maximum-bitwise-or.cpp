class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bit(32,0);
        int n = nums.size();
        vector<int> ans(n);
        for(int i = n-1 ; i >= 0 ; i--){
            int j = 0 ;
            int x = i;
            while(nums[i]){
                if(nums[i]&1)
                    bit[j] = i;
                nums[i] = nums[i]>>1;
                j++;
            }
            for(auto &it : bit)
                x = max(x,it);
            ans[i] = x-i+1;
        }
        return ans;
    }
};