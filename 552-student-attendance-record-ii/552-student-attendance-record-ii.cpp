class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<long>>> dp;
    int helper(int n ,int c,int a){
        if(n == 1){
            if(a && c != 2)
                return 3;
            if(!a && c != 2 || a)
                return 2;
            return 1;
        }
        if(dp[n][c][a] != -1)
            return dp[n][c][a]; 
        long ans = helper(n-1,0,a);
        if(a){
            ans += 1ll*helper(n-1,0,0);
        }
        if(c != 2){
            ans += 1ll*helper(n-1,c+1,a);
        }
        return dp[n][c][a] = ans%mod;
    }
    int checkRecord(int n) {
        dp.resize(n+1,vector<vector<long>>(3,vector<long>(2,-1)));
        return helper(n,0,1)%mod;
    }
};