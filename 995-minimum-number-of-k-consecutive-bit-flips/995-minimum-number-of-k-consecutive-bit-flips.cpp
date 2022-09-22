class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int x = 0;
        int ans = 0;
        int n = nums.size();
        nums.push_back(0);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0){
                x--;
                if(nums[i] == -1)
                    nums[i] = 1;
                else
                    nums[i] = 0;
            }
            if((x%2 == 1 && nums[i] == 1) || (x%2 == 0 && nums[i] == 0)){
                if(i+k > n)
                    return -1;
                ans++;
                nums[i+k] -= 2;
                x++;
            }
        }
        nums.pop_back();
        return ans;
    }
};