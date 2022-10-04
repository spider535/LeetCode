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
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        string temp = s+"$"+r;
        vector<int> z = zalgo(temp);
        int i = s.size();
        int n = temp.size();
        for(int k = i+1; k < n ; k++){
            if(z[k] == n-k)
                return temp.substr(i+1,k-i-1)+s;
        }
        return r+s;
    }
};