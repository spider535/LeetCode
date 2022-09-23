class Solution {
public:
    vector<int> org;
    Solution(vector<int>& nums) {
        org = nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        vector<int> suff = org;
        vector<int> ans;
        while(!suff.empty()){
            int ind = rand()%suff.size();
            ans.push_back(suff[ind]);
            suff[ind] = suff.back();
            suff.pop_back();
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */