class Solution {
public:
    bool is_prime(int x){
        if(x == 1)
            return false;
        for(int i = 2 ; i*i <= x ; i++){
            if(x%i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        while(left <= right){
            int x = __builtin_popcount(left);
            if(is_prime(x)){
                //cout<<left<<" "<<x<<endl;
                ans++;
            }
            left++;
        }
        return ans;
    }
};