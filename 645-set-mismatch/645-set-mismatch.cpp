class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int m,r;
        for(auto &it : nums){
            if(nums[abs(it)-1] < 0){
                r = abs(it);
            }
            else
                nums[abs(it)-1] *= -1;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0)
                m = i+1;
        }
        return {r,m};
    }
};