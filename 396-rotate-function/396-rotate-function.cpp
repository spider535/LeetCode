class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int presum = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += (i*nums[i]);
            presum += nums[i];
        }
        presum -= nums[n-1];
        int temp = ans;
        for(int i = n-1 ; i > 0 ; i--){
            temp -= (n-1)*nums[i];
            temp += presum;
            ans = max(ans,temp);
            presum -= nums[i-1];
            presum += nums[i];
        }
        return ans;
    }
};