class Solution {
public:
    void helper(vector<vector<char>>& board,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] == '.')
            return;
        board[i][j] = '.';
        helper(board,i+1,j,m,n);
        helper(board,i-1,j,m,n);
        helper(board,i,j+1,m,n);
        helper(board,i,j-1,m,n);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] != '.'){
                    ans++;
                    helper(board,i,j,m,n);
                }
            }
        }
        return ans;
    }
};