class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int l = 1,r = 1;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            if(l == 0)
                l = 1;
            l *= nums[i];
            ans = max(ans,l);
        }
        for(int i = n-1 ; i >= 0 ; i--){
            if(r == 0)
                r = 1;
            r *= nums[i];
            ans = max(ans,r);
        }
        return ans;
    }
};