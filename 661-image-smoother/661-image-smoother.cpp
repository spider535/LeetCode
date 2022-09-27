class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int x = img[i][j];
                int y = 1;
                for(auto &it : dir){
                    int ii = i+it.first;
                    int jj = j+it.second;
                    if(ii < 0 || jj < 0 || ii == m || jj == n)
                        continue;
                    x += img[ii][jj];
                    y++;
                }
                ans[i][j] = x/y;
            }
        }
        return ans;
    }
};