class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int helper(vector<int>& loc,int st,int fi,int fuel,int n){
        if(fuel < 0)
            return 0;
        if(dp[st][fuel] != -1)
            return dp[st][fuel];
        long long int ans = 0;
        if(st == fi)
            ans++;
        for(int i = 0 ; i < n ; i++){
            if(i == st)
                continue;
            ans = (ans+helper(loc,i,fi,fuel-abs(loc[i]-loc[st]),n)%mod)%mod;
        }
        return dp[st][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp.resize(n,vector<int>(fuel+1,-1));
        return helper(locations,start,finish,fuel,n)%mod;
    }
};