class Solution {
public:
    int minFlips(string s) {
        int k = s.size();
        s += s;
        int n = s.size();
        int ans = n;
        int t = 0 , t1 = 0;
        for(int i = 0 ; i < k ; i++){
            if(i&1){
                if(s[i] == '1')
                    t++;
                else
                    t1++;
            }
            else{
                if(s[i] == '1')
                    t1++;
                else
                    t++;
            }
        }
        ans = min(t,t1);
        for(int j = k ; j < n ; j++){
            int i = j-k;
            if(i&1){
                if(s[i] == '1')
                    t--;
                else
                    t1--;
            }
            else{
                if(s[i] == '1')
                    t1--;
                else
                    t--;
            }
            if(j&1){
                if(s[j] == '1')
                    t++;
                else
                    t1++;
            }
            else{
                if(s[j] == '1')
                    t1++;
                else
                    t++;
            }
            ans = min(ans,min(t,t1));
        }
        return ans;
    }
};