class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dir = {-1,0,1};
        int ans = 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j < m ; j++){
                for(int k = 0 ; k < m ; k++){
                    int temp = grid[i][j];
                    if(j != k)
                        temp += grid[i][k];
                    if(i == n-1){
                        dp[i][j][k] = temp;
                        continue;
                    }
                    int tt = 0;
                    for(auto &it : dir){
                        int xx = j+it;
                        for(auto &ir :dir){
                            int yy = k+ir;
                            if(xx >= 0 && yy >= 0 && xx < m && yy < m)
                                tt = max(tt,dp[i+1][xx][yy]);
                        }
                    }
                    dp[i][j][k] = temp+tt;
                }
            }
        }
        return dp[0][0][m-1];
        
    }
};