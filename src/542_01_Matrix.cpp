class Solution {
public:
    const int MAX_DIS = 3e4;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if(m == 0) return mat;
        vector<vector<int>> ans(m, vector<int>(n, MAX_DIS));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) ans[i][j] = 0;
                if(i > 0) ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                if(j > 0) ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
            }
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(mat[i][j] == 0) ans[i][j] = 0;
                if(i < m - 1) ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                if(j < n - 1) ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);
            }
        }
        return ans;
    }
};