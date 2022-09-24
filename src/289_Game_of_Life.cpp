class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> flag(board.size(),vector<int>(board[0].size(),0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                if(i > 0 && j >0){
                    if(board[i-1][j-1] == 1) cnt++;
                }
                if(i > 0) if(board[i-1][j]) cnt++;
                if(i > 0 && j+1 < board[0].size()) if(board[i-1][j+1]) cnt++;
                if(j > 0) if(board[i][j-1]) cnt++;
                if(j+1<board[0].size()) if(board[i][j+1]) cnt++;
                if(i+1<board.size() && j>0) if(board[i+1][j-1]) cnt++;
                if(i+1<board.size()) if(board[i+1][j]) cnt++;
                if(i+1<board.size() && j+1<board[0].size()) if(board[i+1][j+1]) cnt++;
                if(board[i][j] == 0){
                    if(cnt == 3) flag[i][j] = 1;
                }
                else{
                    if(cnt == 2 || cnt == 3) flag[i][j] = 1;
                }
                cout<<cnt<<endl;
            }
        }
        board = flag;
    }
};