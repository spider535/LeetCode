class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int r = n;
        for(int i = start ; i < n ; i++){
            if(nums[i] == target){
                r = i-start;
                break;
            }
        }
        for(int i = start-1 ; i >= 0 ; i--){
            if(nums[i] == target){
                r = min(r,start-i);
                break;
            }
        }
        return r;
    }
};