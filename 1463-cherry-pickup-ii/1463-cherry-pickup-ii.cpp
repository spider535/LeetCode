class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dir = {-1,0,1};
        int ans = 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1e9)));
        dp[0][0][m-1] = grid[0][0]+grid[0][m-1];
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = 0 ; k < m ; k++){
                    int temp = grid[i][j];
                    if(j != k)
                        temp += grid[i][k];
                    int tt = -1e9;
                    for(auto &it : dir){
                        int xx = j+it;
                        for(auto &ir :dir){
                            int yy = k+ir;
                            if(xx >= 0 && yy >= 0 && xx < m && yy < m)
                                tt = max(tt,dp[i-1][xx][yy]);
                        }
                    }
                    dp[i][j][k] = temp+tt;
                    ans = max(ans,dp[i][j][k]);
                }
            }
        }
        return ans;
        
    }
};