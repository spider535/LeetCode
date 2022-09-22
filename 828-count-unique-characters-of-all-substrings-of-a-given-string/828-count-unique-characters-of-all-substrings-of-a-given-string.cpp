class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> temp(26,-1);
        vector<int> left(n),right(n);
        for(int i = 0 ; i < n ; i++){
            left[i] = temp[s[i]-'A'];
            temp[s[i]-'A'] = i;
        }
        for(int i = 0 ; i < 26 ; i++)
            temp[i] = n;
        for(int i = n-1 ; i >= 0 ; i--){
            right[i] = temp[s[i]-'A'];
            temp[s[i]-'A'] = i;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += (i-left[i])*(right[i]-i);
        }
        return ans;
    }
};