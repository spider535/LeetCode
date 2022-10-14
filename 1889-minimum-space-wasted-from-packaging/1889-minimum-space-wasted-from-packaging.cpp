class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        for(auto &it : boxes){
            sort(it.begin(),it.end());
        }
        sort(packages.begin(),packages.end());
        vector<long long> presum;
        presum.push_back(0);
        long long x = 0;
        int mod = 1e9+7;
        for(auto &it : packages){
            x += it;
            presum.push_back(x);
        }
        int n = packages.size();
        long long ans = -1;
        for(auto &it : boxes){
            int i = 0;
            long long temp = 0;
            for(auto &ir : it){
                if(i == n)
                    break;
                int j = upper_bound(packages.begin(),packages.end(),ir)-packages.begin();
                long long x = presum[j]-presum[i];
                int y = j-i;
                i = j;
                temp = temp + (1ll*ir*y)-x;
            }
            if(i == n){
                if(ans == -1)
                    ans = temp;
                else
                    ans = min(ans,temp);
            }
        }
        return ans%mod;
    }
};