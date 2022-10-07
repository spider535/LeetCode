class Solution {
public:
    bool helper(string &s,string &t,int i,int j,int m,int n){
        if(i == m)
            return true;
        if(j == n)
            return false;
        if(s[i] == t[j])
            return helper(s,t,i+1,j+1,m,n);
        return helper(s,t,i,j+1,m,n);
    }
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return helper(s,t,0,0,m,n);
    }
};