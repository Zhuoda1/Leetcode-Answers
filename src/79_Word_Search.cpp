class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    board[i][j] = '*';
                    if(dfs(board, word, i, j, 1)) return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
        if(index == word.size()) return true;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == word[index]){
                board[nx][ny] = '*';
                if(dfs(board, word, nx, ny, index + 1)) return true;
                board[nx][ny] = word[index];
            }
        }
        return false;
    }
};