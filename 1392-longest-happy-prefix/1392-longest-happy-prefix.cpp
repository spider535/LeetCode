class Solution {
public:
    vector<int> zalgo(string &s){
        int n = s.size();
        vector<int> z(n,0);
        int l = 0 , r = 0;
        for(int i = 1 ; i < n ; i++){
            if(i > r){
                l = i;
                r = i;
                while(r < n && s[r-l] == s[r])
                    r++;
                r--;
                z[i] = r-l+1;
            }
            else{
                if(z[i-l] < r-i+1)
                    z[i] = z[i-l];
                else{
                    l = i;
                    while(r < n && s[r-l] == s[r])
                        r++;
                    r--;
                    z[i] = r-l+1;
                }
            }
        }
        return z;
    }
    string longestPrefix(string s) {
        vector<int> z = zalgo(s);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(z[i] == n-i)
                return s.substr(i);
        }
        return "";
    }
};