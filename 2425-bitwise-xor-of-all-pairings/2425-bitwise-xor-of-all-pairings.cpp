class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int x = nums1.size();
        int y = nums2.size();
        if(y&1){
            for(auto &it : nums1){
                ans ^= it;
            }
        }
        if(x&1){
            for(auto &it : nums2){
                ans ^= it;
            }
        }
        return ans;
    }
};