class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int column[9][9];
        int grid[3][3][9];

        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(grid,0,sizeof(grid));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int index = board[i][j] - '0' - 1;
                row[i][index]++;
                column[index][j]++;
                grid[i/3][j/3][index]++;
                if(row[i][index] > 1 || column[index][j] > 1 || grid[i/3][j/3][index] > 1) return false;
            }
        }
        return true;
    }
};