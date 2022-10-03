class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int mn = 0;
        int n = nums.size();
        vector<int> left(n),right(n);
        int x = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= mn){
                x++;
            }
            else
                x = 1;
            mn = nums[i];
            left[i] = x;
        }
        x = 0;
        mn = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] <= mn){
                x++;
            }
            else
                x = 1;
            mn = nums[i];
            right[i] = x;
        }
        vector<int> ans;
        for(int i = k ; i < n-k ; i++){
            if(left[i-1] >= k && right[i+1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};