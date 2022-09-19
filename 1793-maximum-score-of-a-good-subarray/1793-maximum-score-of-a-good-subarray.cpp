class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n,1e9);
        temp[k] = nums[k];
        for(int i = k+1 ; i < n ; i++){
            temp[i] = min(temp[i-1],nums[i]);
        }
        for(int i = k-1 ; i >= 0 ; i--){
            temp[i] = min(temp[i+1],nums[i]);
        }
        int i = 0 , j = n-1;
        int ans = 0;
        while(i <= j){
            ans = max(ans,min(temp[i],temp[j])*(j-i+1));
            if(i != k && (temp[i] <= temp[j]) || j == k)
                i++;
            else
                j--;
        }
        return ans;
    }
};