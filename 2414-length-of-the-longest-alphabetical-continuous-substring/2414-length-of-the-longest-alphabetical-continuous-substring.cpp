class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        char curr = 'z';
        int temp = 0;
        for(auto &it : s){
            if(it == curr+1){
                temp++;
                curr++;
            }
            else{
                temp = 1;
                curr = it;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};