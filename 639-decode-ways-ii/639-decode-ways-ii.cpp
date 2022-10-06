class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long>> dp;
    int helper(string &s,int i,int x,int n){
        if(i >= n)
            return 1;
        if(s[i] == '0')
            return 0;
        //cout<<i<<" "<<s[i]<<endl;
        if(i == n-1 && s[i] != '*')
            return 1;
        if(i == n-1)
            return 9;
        if(dp[i][x] != -1)
            return dp[i][x];
        if(s[i] == '*'){
            long ans = 0;
            for(int k = 1 ; k < 10 ; k++){
                s[i] = k+'0';
                ans += 1ll*helper(s,i,k,n);
                s[i] = '*';
            }
            return dp[i][x] = ans%mod;
        }
        if(s[i] > '2' || s[i+1] != '*' && s[i] == '2' && s[i+1] > '6')
            return dp[i][x] = helper(s,i+1,0,n)%mod;
        if(s[i] == '2' && s[i+1] != '*' || s[i] == '1' && s[i+1] != '*')
            return dp[i][x] = (helper(s,i+1,0,n)+helper(s,i+2,0,n))%mod;
        if(s[i] == '2' && s[i+1] == '*'){
            return dp[i][x] = (helper(s,i+1,0,n)+1ll*6*helper(s,i+2,0,n))%mod;
        }
        if(s[i] == '1' && s[i+1] == '*'){
            return dp[i][x] = (helper(s,i+1,0,n)+1ll*9*helper(s,i+2,0,n))%mod;
        }
        return 0;
    }
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n+1,vector<long>(11,-1));
        return helper(s,0,0,n)%mod;
    }
};