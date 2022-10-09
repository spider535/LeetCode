class Solution {
public:
    string helper(int a,int b,int c,char aa,char bb,char cc){
        if(c > b)
            return helper(a,c,b,aa,cc,bb);
        if(b > a)
            return helper(b,a,c,bb,aa,cc);
        if(b == 0)
            return string(min(2,a),aa);
        auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0; 
        return string(use_a, aa) +  string(use_b, bb) + helper(a-use_a,b-use_b,c,aa,bb,cc);
    }
    string longestDiverseString(int a, int b, int c) {
        return helper(a,b,c,'a','b','c');
    }
};