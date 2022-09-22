class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> temp(26);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            temp[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(temp[i].size() < 2)
                continue;
            int l = temp[i][0];
            int r = temp[i].back();
            for(int i = 0 ; i < 26 ; i++){
                auto it = lower_bound(temp[i].begin(),temp[i].end(),l+1);
                if(it != temp[i].end() && *it < r)
                    ans++;
            }
        }
        return ans;
    }
};