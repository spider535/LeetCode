class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            int temp = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(nums[l] + nums[r] == temp){
                    ans.insert({nums[i],nums[l],nums[r]});
                    //int x = nums[l];
                    // while(l < r && nums[l] == x)
                    //     l++;
                    // x = nums[r];
                    // while(l < r && nums[r] == x)
                    //     r--;
                }
                if(nums[l] + nums[r] >= temp)
                    r--;
                else
                    l++;
            }
            while(i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        vector<vector<int>> ans_(ans.begin(),ans.end());
        return ans_;
    }
};