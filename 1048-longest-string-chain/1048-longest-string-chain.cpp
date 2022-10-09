class Solution {
public:
    vector<vector<int>> dp;
    bool static cmp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int helper(vector<string> &words,int i,int j,int n){
        if(i == n)
            return 0;
        if(dp[i][j+1] != -1)
            return dp[i][j+1];
        if(j == -1)
            return dp[i][j+1] = max(helper(words,i+1,j,n),1+helper(words,i+1,i,n));
        bool f2 = true;
        int f1 = 1;
        int k = 0 , l = 0 , n1 = words[i].size() , n2 = words[j].size();
        for(; k < n2 ; k++){
            if(l == n1){
                f2 = false;
                break;
            }
            if(f1 && words[i][l] != words[j][k]){
                l++;
                f1 = 0;
            }
            if(l == n1 || !f1 && words[i][l] != words[j][k]){
                f2 = false;
                break;
            }
            l++;
        }
        if(!f2 || l+f1 != n1)
            return dp[i][j+1] = helper(words,i+1,j,n);
        return dp[i][j+1] = max(helper(words,i+1,j,n),1+helper(words,i+1,i,n));
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        dp.resize(n,vector<int>(n+1,-1));
        return helper(words,0,-1,n);
    }
};