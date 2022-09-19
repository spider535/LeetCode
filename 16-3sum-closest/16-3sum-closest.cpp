class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1e9;
        int ans_;
        for(int i = 0 ; i < n ; i++){
            int temp = target-nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(ans > abs(temp-nums[l]-nums[r])){
                    ans = abs(temp-nums[l]-nums[r]);
                    ans_ = nums[i]+nums[l]+nums[r];
                }
                if(nums[l] + nums[r] > temp)
                    r--;
                else
                    l++;
            }
            while(i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans_;
    }
};