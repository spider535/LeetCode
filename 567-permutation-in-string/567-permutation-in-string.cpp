class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        vector<int> t1(26,0),t2(26,0);
        for(auto &it : s1){
            t1[it-'a']++;
        }
        int m = s2.size();
        if(n > m)
            return false;
        int i;
        for(i = 0 ; i < n ; i++){
            t2[s2[i]-'a']++;
        }
        bool flag = true;
        for(int j = 0 ; j < 26 && flag ; j++){
            if(t1[j] != t2[j])
                flag = false;
        }
        if(flag)
            return true;
        for(;i < m ; i++){
            t2[s2[i-n]-'a']--;
            t2[s2[i]-'a']++;
            flag = true;
            for(int j = 0 ; j < 26 && flag ; j++){
                if(t1[j] != t2[j])
                    flag = false;
            }
            if(flag)
                return true;
        }
        return false;
    }
};