class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        int n = p.size();
        int cnt = 1;
        vector<int> temp(26,0);
        temp[p[0]-'a']++;
        for(int i = 1 ; i < n ; i++){
            int x = p[i-1]-'a';
            int y = p[i]-'a';
            if((x+1)%26 == y)
                cnt++;
            else
                cnt = 1;
            temp[p[i]-'a'] = max(temp[p[i]-'a'],cnt);
        }
        for(auto &it : temp)
            ans += it;
        return ans;
    }
};