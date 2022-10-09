class Solution {
public:
    vector<int> zalgo(string &s,int a,int b){
        int n = b-a+1;
        vector<int> z(n,0);
        int l = 0 , r = 0;
        for(int i = 1 ; i < n ; i++){
            if(i > r){
                l = i;
                r = i;
                while(r < n && s[r+a] == s[r-l+a])
                    r++;
                r--;
                z[i] = r-l+1;
            }
            else{
                if(z[i-l] < r-i+1)
                    z[i] = z[i-l];
                else{
                    l = i;
                    while(r < n && s[r+a] == s[r-l+a])
                        r++;
                    r--;
                    z[i] = r-l+1;
                }
            }
        }
        return z;
    }
    int helper(string &text,int i,int j){
        if(i == j)
            return 1;
        if(i > j)
            return 0;
        vector<int> z = zalgo(text,i,j);
        int n = z.size();
        int ind = 0;
        for(int i = (n+1)/2 ; i < n ; i++){
            if(z[i] == n-i)
                ind = n-i;
        }
        if(ind == 0)
            return 1;
        return 2+helper(text,i+ind,j-ind);
    }
    int longestDecomposition(string text) {
        int n = text.size();
        return helper(text,0,n-1);
    }
};