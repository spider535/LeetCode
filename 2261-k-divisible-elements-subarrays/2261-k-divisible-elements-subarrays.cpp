class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int n = nums.size();
        for(int j = 0 ; j < n ; j++){
            vector<int> temp;
            int cnt = 0;
            for(int i = j ; i < n ; i++){
                if(nums[i] % p == 0)
                    cnt++;
                if(cnt > k)
                    break;
                temp.push_back(nums[i]);
                st.insert(temp);
            }
        }
        return st.size();
    }
};