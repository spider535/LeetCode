class Solution {
public:
    vector<int> zalgo(string &s,int x){
        int n = s.size();
        vector<int> z(n-x,0);
        int l = x , r = x;
        for(int i = x+1 ; i < n ; i++){
            if(i > r){
                l = i;
                r = i;
                while(r < n && s[r-l+x] == s[r])
                    r++;
                r--;
                z[i-x] = r-l+1;
            }
            else{
                if(z[i-l] < r-i+1)
                    z[i-x] = z[i-l];
                else{
                    l = i;
                    while(r < n && s[r-l+x] == s[r])
                        r++;
                    r--;
                    z[i-x] = r-l+1;
                }
            }
        }
        return z;
    }
    vector<int> dp;
    int helper(string &s,int i){
        int n = s.size();
        if(i >= n)
            return 0;
        if(i == n-1)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        vector<int> z = zalgo(s,i);
        for(int k = 1 ; k < z.size() ; k++){
            if(z[k] >= k){
                ans = max(ans,helper(s,k+i));
            }
        }
        return dp[i] = ans+1;
    }
    int deleteString(string s) {
        int n = s.size();
        dp.resize(n,-1);
        return helper(s,0);
    }
};