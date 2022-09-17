class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int x = 0;
        for(auto &it : nums)
            if(it == 1)
                x++;
        int n = nums.size();
        int j = 0 , i = 0;
        int temp = x;
        for(j = 0 ; j < x ; j++){
            if(nums[j] == 1)
                temp--;
        }
        int ans = temp;
        for(i = 0 ; i < n ; i++){
            if(j == n)
                j = 0;
            if(nums[i] == 1)
                temp++;
            if(nums[j++] == 1)
                temp--;
            ans = min(ans,temp);
        }
        return ans;
    }
};