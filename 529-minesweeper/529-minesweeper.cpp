class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};
    void helper(vector<vector<char>>& board,int i,int j,int m,int n){
        if(board[i][j] == 'M'){
            board[i][j] = 'X';
            return;
        }
        int cnt = 0;
        for(auto it : dir){
            int x = i+it.first;
            int y = j+it.second;
            if(x < 0 || y < 0 || x == m || y == n)
                continue;
            if(board[x][y] == 'M')
                cnt++;
        }
        if(cnt > 0){
            board[i][j] = cnt+'0';
            return;
        }
        board[i][j] = 'B';
        for(auto it : dir){
            int x = i+it.first;
            int y = j+it.second;
            if(x < 0 || y < 0 || x == m || y == n || board[x][y] != 'E')
                continue;
            helper(board,x,y,m,n);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        helper(board,click[0],click[1],board.size(),board[0].size());
        return board;
    }
};