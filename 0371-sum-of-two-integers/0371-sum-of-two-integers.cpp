class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int f = 0,s = 0;
            if(a & (1<<i))
                f = 1;
            if(b & (1<<i))
                s = 1;
            
            ans |= ((f^s^c)<<i);
            if(f && s || f && c || s && c)
                c = 1;
            else
                c = 0;
        }
        return ans;
    }
};