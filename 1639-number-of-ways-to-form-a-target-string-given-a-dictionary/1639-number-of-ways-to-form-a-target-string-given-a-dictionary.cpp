class Solution {
public:
    vector<vector<int>> temp;
    vector<vector<long>> dp;
    int mod = 1e9+7;
    int helper(string &target,int i,int j,int m,int n){
        if(j == n)
            return 1;
        if(i == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j]%mod;
        long ans = 0;
        if(temp[i][target[j]-'a'])
                ans = (1ll*temp[i][target[j]-'a']*helper(target,i+1,j+1,m,n))%mod;
        ans = (ans%mod + helper(target,i+1,j,m,n)%mod)%mod;
        return dp[i][j] = ans%mod;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        temp.resize(m,vector<int>(26,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                temp[i][words[j][i]-'a']++;
            }
        }
        n = target.size();
        dp.resize(m,vector<long>(n,-1));
        return helper(target,0,0,m,n)%mod;
    }
};