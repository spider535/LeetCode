class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto &it : t)
            mp[it]++;
        unordered_map<char,int> mp1;
        int i = 0;
        int temp = 0;
        int st = -1;
        int len = 1e9;
        int n = s.size();
        for(int j = 0 ; j < n ; j++){
            if(!mp.count(s[j]))
                continue;
            mp1[s[j]]++;
            if(mp1[s[j]] == mp[s[j]])
                temp++;
            while(i <= j && temp == mp.size()){
                if(j-i+1 < len){
                    len = j-i+1;
                    st = i;
                }
                if(!mp.count(s[i])){
                    i++;
                    continue;
                }
                mp1[s[i]]--;
                if(mp1[s[i]] < mp[s[i]])
                    temp--;
                i++;
            }
        }
        if(st == -1)
            return "";
        return s.substr(st,len);
    }
};