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
    string removeOccurrences(string s, string part) {
        bool flag = true;
        int m = part.size();
        while(flag){
            flag = false;
            string temp = part+"$"+s;
            vector<int> z = zalgo(temp);
            string x;
            int n = temp.size();
            bool f = true;
            for(int i = m+1 ; i < n ; i++){
                if(f && z[i] == m){
                    i += m-1;
                    flag = true;
                    f = false;
                }
                else
                    x.push_back(temp[i]);
            }
            s = x;
        }
        return s;
    }
};