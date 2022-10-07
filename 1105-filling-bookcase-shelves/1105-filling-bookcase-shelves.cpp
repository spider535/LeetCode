class Solution {
public:
    vector<int> dp;
    int helper(vector<vector<int>>& books,int i,int n,int sw){
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int h = 0;
        int w = sw;
        int ans = INT_MAX;
        for(int k = i ; k < n ; k++){
            if(books[k][0] > w){
                break;
            }
            h = max(h,books[k][1]);
            w -= books[k][0];
            ans = min(ans,h+helper(books,k+1,n,sw));
        }
        return dp[i] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n = books.size();
        dp.resize(n,-1);
        return helper(books,0,n,sw);
    }
};