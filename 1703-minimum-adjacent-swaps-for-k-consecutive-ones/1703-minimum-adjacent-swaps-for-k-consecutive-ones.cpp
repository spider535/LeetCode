class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> A;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1)
                A.push_back(i);
        }
        int n = A.size();
        vector<long> B(1);
        for(int i = 0 ; i < n ; i++){
            B.push_back(1ll*(B.back()+A[i]));
        }
        long ans = 2e9;
        for(int i = 0 ; i < n-k+1 ; i++){
            ans = min(ans,B[i + k] - B[k / 2 + i] - B[(k + 1) / 2 + i] + B[i]);
        }
        ans -= (k / 2) * ((k + 1) / 2);
        return ans;
    }
};