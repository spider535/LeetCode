class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> seen(n,false);
        for(int i = 2 ; i < n ; i++){
            if(seen[i])
                continue;
            ans++;
            for(int j = i ; j < n ;){
                seen[j] = true;
                j += i;
            }
        }
        return ans;
    }
};