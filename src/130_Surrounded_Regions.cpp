class Solution {
public:
    int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    void dfs(vector<vector<char>>& board, int x, int y){
        board[x][y] = '#';
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O') dfs(board, nx, ny);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[n-1][j] == 'O') dfs(board, n-1, j);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};