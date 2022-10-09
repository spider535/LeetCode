class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        long long one = 0 , zero = 0;
        long long mod = 1e9+7;
        long long ans = 1ll;
        bool flag = false;
        for(auto &it : binary){
            long long t = ans;
            if(it == '0'){
                flag = true;
                ans = ((ans*2ll - 1ll)%mod - zero%mod +mod)%mod;
                ans%=mod;
                zero = (t-1ll);
                zero%=mod;
            } 
            else{
                ans = (ans*2ll - one%mod +mod)%mod;
                ans%=mod;
                one = t;
                one%=mod;
            }
        }
        if(!flag)
            ans = (ans-1ll);
        return ans%mod;
    }
};