class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[2][1003] = {};
        int n1 = text1.size();
        int n2 = text2.size();
        for(int i = 0; i < n1; ++i){
            for(int j = 0; j < n2; ++j){
                dp[!(i % 2)][j + 1] = text1[i] == text2[j] ? dp[i % 2][j] + 1 : max(dp[i % 2][j + 1], dp[!(i % 2)][j]);
            }
        }
        return dp[n1 % 2][n2];
    }
};