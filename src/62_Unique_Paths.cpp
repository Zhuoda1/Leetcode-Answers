class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        int left,up;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                left = j >= 1 ? dp[i][j-1] : 0;
                up = i >= 1 ? dp[i-1][j] : 0;
                dp[i][j] += left + up;
            }
        }
        return dp[m-1][n-1];
    }
};