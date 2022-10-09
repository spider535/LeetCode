class Solution {
public:
    int mod = 1000000007;
    int distinctSubseqII(string s) {
        vector<int> temp(26,0);
        long ans = 1;
        for(auto &it : s){
            long t = ans;
            ans = (2ll*ans-temp[it-'a']+mod)%mod;
            temp[it-'a'] = t%mod;
        }
        return ans%mod-1;
    }
};