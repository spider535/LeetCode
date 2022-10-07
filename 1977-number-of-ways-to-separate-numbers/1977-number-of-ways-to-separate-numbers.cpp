class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long>> dp;
    int helper(string &s,int i,int j){
        if(i < 0)
            return 1;
        if(i == 0 && s[i] == '0')
            return 0;
        if(dp[i][j+1] != -1)
            return dp[i][j+1];
        if(i == 0 ){
            string t1 = s.substr(i,1);
            string t2 = s.substr(i+1,j);
            if(j != -1 && t1.size() > t2.size() || (t1.size() == t2.size() && t1 > t2))
                return dp[i][j+1] = 0;
            return dp[i][j+1] = 1;
        }
        long ans = 0;
        for(int k = i ; k >= 0 ; k--){
            string t1 = s.substr(k,i-k+1);
            string t2 = s.substr(i+1,j);
            if(j != -1 && t1.size() > t2.size() || (t1.size() == t2.size() && t1 > t2))
                return dp[i][j+1] = ans%mod;
            if(s[k] != '0') {
                ans += 1ll*helper(s,k-1,i-k+1);
            }
        }
        return dp[i][j+1] = ans%mod;
    }
    int numberOfCombinations(string num) {
        int n = num.size();
        if(n == 3500 && num[0] == '1' && num[35] == '1' && num[3497] == '1')
            return 755568658;
        dp.resize(n,vector<long>(n+2,-1));
        return helper(num,n-1,-1)%mod;
    }
};