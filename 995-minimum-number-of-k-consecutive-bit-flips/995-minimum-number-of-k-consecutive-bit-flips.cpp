class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int x = 0;
        int ans = 0;
        queue<int> qe;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(!qe.empty() && i == qe.front()){
                x--;
                qe.pop();
            }
            if((x%2 == 1 && nums[i] == 1) || (x%2 == 0 && nums[i] == 0)){
                if(i+k > n)
                    return -1;
                ans++;
                qe.push(i+k);
                x++;
            }
        }
        return ans;
    }
};