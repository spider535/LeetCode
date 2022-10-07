class Solution {
public:
    vector<long> dp;
    int mod = 1e9+7;
    int helper(string &s,int i,int k){
        if(i < 0 || i == 0 && s[i] != 0)
            return 1;
        if(i == 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        long ans = 0;
        for(int j = i ; j >= 0 && i-j < 10 ; j--){
            if(s[j] != '0'){
                string t = s.substr(j,i-j+1);
                if(stol(t) > k)
                    return dp[i] = ans%mod;
                ans += 1ll*helper(s,j-1,k);
            }
        }
        return dp[i] = ans%mod;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.resize(n,-1);
        return helper(s,n-1,k)%mod;
    }
};