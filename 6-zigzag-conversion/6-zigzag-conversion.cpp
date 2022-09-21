class Solution {
public:
    string convert(string s, int n) {
        if(n == 1)
            return s;
        int m = s.length();
        vector<string> temp(n);
        int i = 0 ;
        bool f = true;
        for(auto &it : s){
            temp[i].push_back(it);
            if(f){
                i++;
            }
            if(f && i == n-1){
                f = false;
            }
            else if(!f){
                i--;
            }
            if(i == 0){
                f = true;
            }
        }
        string ans = "";
        for(auto &it : temp){
            ans += it;
        }
        return ans;
    }
};