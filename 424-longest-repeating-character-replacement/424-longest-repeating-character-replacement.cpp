class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> temp(26,0);
        int n = s.size();
        int i = 0 , j = 0;
        int ans = 0;
        while(j < n){
            bool flag = true;
            int sum = 0;
            int mx = 0;
            for(int k = 0 ; k < 26;k++){
                sum += temp[k];
                mx = max(mx,temp[k]);
            }
            sum -= mx;
            if(sum <= k){
                ans = max(ans,sum+mx);
                temp[s[j++]-'A']++;
            }
            else
                temp[s[i++]-'A']--;
        }
        int sum = 0;
        int mx = 0;
        for(int k = 0 ; k < 26;k++){
            sum += temp[k];
            mx = max(mx,temp[k]);
        }
        sum -= mx;
        if(sum <= k)
            ans = max(ans,sum+mx);
        return ans;
    }
};