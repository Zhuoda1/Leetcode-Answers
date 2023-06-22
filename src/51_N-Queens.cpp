class Solution {
public:
    void backTracking(vector<vector<string>>& ans, vector<string>& cur, int row, vector<int> &flag, int n){
        if(row == n){
            ans.push_back(cur);
            return;
        }
        for(int col = 0; col < n; col++){
            if(flag[col] && flag[n + row + col] && flag[4*n-2+col-row]){
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = 0;
                cur[row][col] = 'Q';
                backTracking(ans, cur, row+1, flag, n);
                cur[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = 1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) return {{"Q"}};
        if(n == 2 || n == 3) return {};
        vector<vector<string>> ans;
        vector<int> flag(5 * n - 2, 1);
        vector<string> cur(n, string(n, '.'));
        backTracking(ans, cur, 0, flag, n);
        return ans;
    }
};