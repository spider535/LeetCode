class Solution {
public:
    vector<int> bit;
    int sum(int i){
        int ans = 0;
        while(i > 0){
            ans+=bit[i];
            i -= (i&-i);
        }
        return ans;
    }
    void update(int i,int val){
        while(i < 1e5){
            bit[i] += val;
            i += (i&-i);
        }
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        for(auto &it : nums){
            it += 10000+1;
        }
        bit.resize(8*1e4,0);
        vector<int> ans;
        int n = nums.size();
        for(int i = n-1 ; i>= 0 ;i--){
            int it = nums[i];
            ans.push_back(sum(it-1));
            update(it,1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};