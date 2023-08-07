class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<char> row(201, '1');
        vector<char> col(201, '1');
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = '0';
                    col[j] = '0';
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(row[i] == '0'){
                for(int j = 0; j < m; j++) matrix[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++){
            if(col[i] == '0'){
                for(int j = 0; j < n; j++) matrix[j][i] = 0;
            }
        }
    }
};