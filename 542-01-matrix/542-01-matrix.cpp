class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> qe;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    qe.push({i,j});
                }
                else 
                    mat[i][j] = -1;
            }
        }
        while(!qe.empty()){
            auto x = qe.front();
            qe.pop();
            int i = x.first;
            int j = x.second;
            for(auto &it : dir){
                int ii = i+it.first;
                int jj = j+it.second;
                if(ii < 0 || jj < 0 || ii == m || jj == n || mat[ii][jj] != -1)
                    continue;
                mat[ii][jj] = mat[i][j] + 1;
                qe.push({ii,jj});
            }
        }
        return mat;
    }
};