class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int i,int n){
        if(i == n){
            ans.push_back(nums);
            return;;
        }
        for(int k = i ; k < n ; k++){
            swap(nums[i],nums[k]);
            helper(nums,i+1,n);
            swap(nums[i],nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0,nums.size());
        return ans;
    }
};